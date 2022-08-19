cmd_/home/krautkraft/lkm/radio/modules.order := {   echo /home/krautkraft/lkm/radio/radio.ko; :; } | awk '!x[$$0]++' - > /home/krautkraft/lkm/radio/modules.order
