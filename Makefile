STUID = ysyx_22040000
STUNAME = 张三

# DO NOT modify the following code!!!

TRACER = tracer-ysyx2204
GITFLAGS = -q --author='$(TRACER) <tracer@ysyx.org>' --no-verify --allow-empty
OTHER_MSG = echo $(STUID) $(STUNAME) && uname -a && uptime

YSYX_HOME = $(NEMU_HOME)/..

# prototype: git_commit(msg)
define git_commit
	-@while (test -e $(YSYX_HOME)/.git/index.lock); do sleep 0.1; done;  # wait for other git instances
	-@git -C $(YSYX_HOME) branch $(TRACER) -q 2>/dev/null || true        # create tracer branch if not existent
	-@git -C $(YSYX_HOME) worktree add $(TRACER) -q                      # check out tracer branch
	-@# list changed files to trace (w/o quotes)   | extract file path | skip tracer worktree  | copy files
	-@cd $(YSYX_HOME) && git status -u --porcelain | awk '{print $$2}' | grep -v '^$(TRACER)/' | rsync -aq --files-from=- ./ $(TRACER)/
	-@git -C $(YSYX_HOME)/$(TRACER) add . -A --ignore-errors             # add changes to staging area
	-@# generate commit message       | commit changes in tracer branch
	-@(echo "> $(1)" && $(OTHER_MSG)) | git -C $(YSYX_HOME)/$(TRACER) commit -F - $(GITFLAGS)
	-@git -C $(YSYX_HOME) worktree remove $(TRACER) -f                   # remove tracer worktree
	-@sync
endef

_default:
	@echo "Please run 'make' under subprojects."

.PHONY: _default
