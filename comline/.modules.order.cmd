cmd_/home/krautkraft/lkm/comline/modules.order := {   echo /home/krautkraft/lkm/comline/comline.ko; :; } | awk '!x[$$0]++' - > /home/krautkraft/lkm/comline/modules.order
