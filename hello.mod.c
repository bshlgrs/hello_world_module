#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x5358b4ed, "module_layout" },
	{ 0xf192d0b1, "single_release" },
	{ 0xca67c6cb, "seq_read" },
	{ 0xd764127b, "seq_lseek" },
	{ 0x2caa7919, "remove_proc_entry" },
	{ 0x377165d0, "proc_create_data" },
	{ 0x27e1a049, "printk" },
	{ 0xd74c8f46, "__mutex_init" },
	{ 0x181af9d0, "mutex_unlock" },
	{ 0x4f6b400b, "_copy_from_user" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0xd2b09ce5, "__kmalloc" },
	{ 0x37a0cba, "kfree" },
	{ 0xb264abed, "mutex_lock" },
	{ 0x789bdca3, "seq_printf" },
	{ 0xbf50d31, "single_open" },
	{ 0xbdfb6dbb, "__fentry__" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "830BFF92B543F0EB2D91101");
