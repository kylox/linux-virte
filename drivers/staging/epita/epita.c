#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>

#define DRV_NAME "epita"

static int epita_probe(struct plateform_device *pdev)
{
	return 0;
}

static int epita_remove(struct plateform_device *pdev)
{
	return 0;
}

static const struct of_device_id epita_of_match[] = {
	{.compatible = "epita,test-42", .data = (void *)42},
	{.compatible = "epita,test-0", .data = (void*)1},
	{/*sentinel*/},
};
MODULE_DEVICE_TABLE(of, epita_of_match);


static struct platform_driver epita_sid_driver = {
	.probe = epita_probe,
	.remove = epita_remove,
	.driver = {
		.name = DRV_NAME,
		.of_match_table = epita_of_match,
	},
};


MODULE_AUTHOR("Maxime Gaudron");
MODULE_DESCRIPTION("EPITA tests module");
MODULE_LICENSE("GPL");
