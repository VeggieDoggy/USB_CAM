#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0xdd8f8694, "module_layout" },
	{ 0x21ed5d7a, "video_ioctl2" },
	{ 0x867847b8, "usb_deregister" },
	{ 0x785cf894, "usb_register_driver" },
	{ 0x308fbb29, "__video_register_device" },
	{ 0x184ecfcd, "v4l2_device_register" },
	{ 0xca7a3159, "kmem_cache_alloc_trace" },
	{ 0x428db41d, "kmalloc_caches" },
	{ 0x173cd87c, "video_device_alloc" },
	{ 0x7c0ac1e9, "v4l2_device_unregister" },
	{ 0x77f95982, "video_unregister_device" },
	{ 0xa729cb8f, "video_device_release" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "videodev");


MODULE_INFO(srcversion, "39D48D381086A7DAC131067");
