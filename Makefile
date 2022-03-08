STUID = ysyx_22040000
STUNAME = 张三

# DO NOT modify the following code!!!

TRACER = tracer-ysyx2204
GITFLAGS = -q --author='$(TRACER) <tracer@ysyx.org>' --no-verify --allow-empty

YSYX_HOME = $(NEMU_HOME)/..
WORK_BRANCH = $(shell git rev-parse --abbrev-ref HEAD)
WORK_INDEX = $(YSYX_HOME)/.git/index.$(WORK_BRANCH)
TRACER_BRANCH = $(TRACER)

LOCK_DIR = $(YSYX_HOME)/.git/

# prototype: git_soft_checkout(branch)
define git_soft_checkout
	git checkout --detach -q && git reset --soft $(1) -q && git checkout $(1) -q
endef

# prototype: git_commit(msg)
define git_commit
	-@flock $(LOCK_DIR) $(MAKE) .git_commit MSG='$(1)'
	-@sync
endef

.git_commit:
	-@cd $(YSYX_HOME) && while (test -e .git/index.lock); do sleep 0.1; done;               `# wait for other git instances`
	-@cd $(YSYX_HOME) && git branch $(TRACER_BRANCH) -q 2>/dev/null || true                 `# create tracer branch if not existent`
	-@cd $(YSYX_HOME) && cp -a .git/index $(WORK_INDEX)                                     `# backup git index`
	-@cd $(YSYX_HOME) && $(call git_soft_checkout, $(TRACER_BRANCH))                        `# switch to tracer branch`
	-@cd $(YSYX_HOME) && git add . -A --ignore-errors                                       `# add files to commit`
	-@cd $(YSYX_HOME) && (echo "> $(MSG)" && echo $(STUID) $(STUNAME) && uname -a && uptime `# generate commit msg`) \
	                | git commit -F - $(GITFLAGS)                                           `# commit changes in tracer branch`
	-@cd $(YSYX_HOME) && $(call git_soft_checkout, $(WORK_BRANCH))                          `# switch to work branch`
	-@cd $(YSYX_HOME) && mv $(WORK_INDEX) .git/index                                        `# restore git index`

.clean_index:
	rm -f $(WORK_INDEX)

_default:
	@echo "Please run 'make' under subprojects."

.PHONY: .git_commit .clean_index _default
