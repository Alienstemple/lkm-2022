cmd_/home/krautkraft/lkm/proc_demo/Module.symvers := sed 's/\.ko$$/\.o/' /home/krautkraft/lkm/proc_demo/modules.order | scripts/mod/modpost -m -a  -o /home/krautkraft/lkm/proc_demo/Module.symvers -e -i Module.symvers   -T -
