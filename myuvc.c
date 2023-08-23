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
    struct usb_device *dev = interface_to_usbdev(intf);
    struct usb_device_descriptor *descriptor = &dev->descriptor;
    printk("%s : cnt = %d", __FUNCTION__, cnt++);

    printk("Device Descriptor:\n"
	       "  bLength             %5u\n"
	       "  bDescriptorType     %5u\n"
	       "  bcdUSB              %2x.%02x\n"
	       "  bDeviceClass        %5u \n"
	       "  bDeviceSubClass     %5u \n"
	       "  bDeviceProtocol     %5u \n"
	       "  bMaxPacketSize0     %5u\n"
	       "  idVendor           0x%04x \n"
	       "  idProduct          0x%04x \n"
	       "  bcdDevice           %2x.%02x\n"
	       "  iManufacturer       %5u\n"
	       "  iProduct            %5u\n"
	       "  iSerial             %5u\n"
	       "  bNumConfigurations  %5u\n",
	       descriptor->bLength, descriptor->bDescriptorType,
	       descriptor->bcdUSB >> 8, descriptor->bcdUSB & 0xff,
	       descriptor->bDeviceClass, 
	       descriptor->bDeviceSubClass,
	       descriptor->bDeviceProtocol, 
	       descriptor->bMaxPacketSize0,
	       descriptor->idVendor,  descriptor->idProduct,
	       descriptor->bcdDevice >> 8, descriptor->bcdDevice & 0xff,
	       descriptor->iManufacturer, 
	       descriptor->iProduct, 
	       descriptor->iSerialNumber, 
	       descriptor->bNumConfigurations);

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