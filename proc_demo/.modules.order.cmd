cmd_/home/krautkraft/lkm/proc_demo/modules.order := {   echo /home/krautkraft/lkm/proc_demo/proc_demo.ko; :; } | awk '!x[$$0]++' - > /home/krautkraft/lkm/proc_demo/modules.order
