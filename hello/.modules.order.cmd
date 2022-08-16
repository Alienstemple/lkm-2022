cmd_/home/krautkraft/lkm/hello/modules.order := {   echo /home/krautkraft/lkm/hello/hello.ko; :; } | awk '!x[$$0]++' - > /home/krautkraft/lkm/hello/modules.order
