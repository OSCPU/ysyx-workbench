STUID = ysyx_22040000
STUNAME = 张三

# DO NOT modify the following code!!!

TRACER = tracer-ysyx2204
GITFLAGS = -q --author='$(TRACER) <tracer@ysyx.org>' --no-verify --allow-empty

YSYX_HOME = $(NEMU_HOME)/..
TRACER_BRANCH = $(TRACER)

# prototype: git_commit(msg)
define git_commit
	-@cd $(YSYX_HOME) && while (test -e .git/index.lock); do sleep 0.1; done;  `# wait for other git instances`
	-@cd $(YSYX_HOME) && git branch $(TRACER_BRANCH) -q 2>/dev/null || true    `# create tracer branch if not existent`
	-@cd $(YSYX_HOME) && git worktree add $(TRACER_BRANCH) -q                  `# check out tracer branch`
	-@cd $(YSYX_HOME) && git status --untracked-files -z                       `# list changed files to copy (w/o quotes)` \
			| tr '\000' '\n'                                           `# restore EOL sequence`                    \
			| cut -c 1-3 --complement                                  `# remove status indicator`                 \
			| grep -v '^$(TRACER_BRANCH)/'                             `# skip tracer worktree`                    \
			| rsync -aq --files-from=- ./ $(TRACER_BRANCH)/            `# call rsync to copy files`
	-@cd $(YSYX_HOME) && git -C $(TRACER_BRANCH) add . -A --ignore-errors      `# add changes to staging area`
	-@cd $(YSYX_HOME) && (echo "> $(1)" && echo $(STUID) $(STUNAME) && uname -a && uptime `# generate commit msg`)         \
			| git -C $(TRACER_BRANCH) commit -F - $(GITFLAGS)          `# commit changes in tracer branch`
	-@cd $(YSYX_HOME) && git worktree remove $(TRACER_BRANCH) -f               `# remove tracer worktree`
	-@sync
endef

_default:
	@echo "Please run 'make' under subprojects."

.PHONY: _default
