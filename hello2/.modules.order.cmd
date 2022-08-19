cmd_/home/krautkraft/lkm/hello2/modules.order := {   echo /home/krautkraft/lkm/hello2/hello.ko; :; } | awk '!x[$$0]++' - > /home/krautkraft/lkm/hello2/modules.order
