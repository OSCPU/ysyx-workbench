cd ..  # go up to the ysyx-workbench directory

d="apps/pal/repo"
if [[ ! -d navy-apps/$d ]]; then
  cp -r $NAVY_HOME/$d `dirname navy-apps/$d`
  mkdir -p navy-apps/fsimg/share/games
else
  echo navy-apps/$d already exists
fi
d="apps/bird/repo"
if [[ ! -d navy-apps/$d ]]; then
  cp -r $NAVY_HOME/$d `dirname navy-apps/$d`
  mkdir -p navy-apps/fsimg/share/games
else
  echo navy-apps/$d already exists
fi
d="libs/libc"
if [[ ! -d navy-apps/$d ]]; then
  cp -r $NAVY_HOME/$d `dirname navy-apps/$d`
else
  echo navy-apps/$d already exists
fi

d="tools/spike-diff/repo"
if [[ ! -d nemu/$d ]]; then
  cp -r $NEMU_HOME/$d `dirname nemu/$d`
else
  echo nemu/$d already exists
fi

d="../am-kernels"
if [[ ! -d nemu/$d ]]; then
  cp -r $NEMU_HOME/$d `dirname nemu/$d`
else
  echo `dirname nemu/$d` already exists
fi

source ysyx-exam/setup-env.sh

find $NAVY_HOME -name Makefile | xargs sed -i -e '/git clone/d'

make -s -C $NAVY_HOME -j clean-all 2> /dev/null

make -C $NEMU_HOME -j distclean
touch $NEMU_HOME/.config
cp ysyx-exam/exam_defconfig $NEMU_HOME/configs/
make -C $NEMU_HOME exam_defconfig
d="ISA=native"
make -C $NAVY_HOME/apps/pal $d install
make -C $NAVY_HOME/apps/bird $d install
