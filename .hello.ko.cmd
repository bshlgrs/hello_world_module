cmd_/scratch/u5192430/hello_module/hello.ko := ld -r -m elf_x86_64 -T /usr/src/linux-headers-3.8.0-41-generic/scripts/module-common.lds --build-id  -o /scratch/u5192430/hello_module/hello.ko /scratch/u5192430/hello_module/hello.o /scratch/u5192430/hello_module/hello.mod.o