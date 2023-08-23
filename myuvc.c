#include <linux/printk.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/module.h>
#include <linux/usb.h>
#include <linux/videodev2.h>
#include <linux/vmalloc.h>
#include <linux/wait.h>

#include <media/v4l2-common.h>

static int myuvc_probe(struct usb_interface *intf, const struct usb_device_id *id) {
    static int cnt;
    printk("%s : cnt = %d", __FUNCTION__, cnt++);
    return 0;
}

static void myuvc_disconnect(struct usb_interface *intf) {
    static int cnt;
    printk("%s : cnt = %d", __FUNCTION__, cnt++);
}

static struct usb_device_id myuvc_ids[] = {
    /* Generic USB Video Class */
	{ USB_INTERFACE_INFO(USB_CLASS_VIDEO, 1, 0) },  // VideoControl Interface
    { USB_INTERFACE_INFO(USB_CLASS_VIDEO, 2, 0) },  // VideoStreaming Interface
	{}
};


static struct usb_driver myuvc_driver = {
    .name		= "myuvc",
	.probe		= myuvc_probe,
	.disconnect	= myuvc_disconnect,
	.id_table	= myuvc_ids,
};

static int __init myuvc_init(void){
    usb_register(&myuvc_driver);
    return 0;
}

static void __exit myuvc_exit(void){
    usb_deregister(&myuvc_driver);
}

module_init(myuvc_init);
module_exit(myuvc_exit);
MODULE_LICENSE("GPL");