#include "mailbox.h"

MODULE_LICENSE("Dual BSD/GPL");

static void get_process_name(char *ouput_name);

//to implement Peter
static ssize_t mailbox_read(struct kobject *kobj,
                            struct kobj_attribute *attr, char *buf);
static ssize_t mailbox_write(struct kobject *kobj,
                             struct kobj_attribute *attr, const char *buf, size_t count);

static struct kobject *hw2_kobject;
static struct kobj_attribute mailbox_attribute
    = __ATTR(mailbox, 0660, mailbox_read, mailbox_write);

static int num_entry_max = 2;

module_param(num_entry_max, int, S_IRUGO);

static void get_process_name(char *ouput_name)
{
	memcpy(ouput_name, current->comm, sizeof(current->comm));
}

static ssize_t mailbox_read(struct kobject *kobj,
                            struct kobj_attribute *attr, char *buf)
{
	return ERR_EMPTY;
}

static ssize_t mailbox_write(struct kobject *kobj,
                             struct kobj_attribute *attr, const char *buf, size_t count)
{
	return ERR_FULL;
}

static int __init mailbox_init(void)
{
	printk("Insert\n");
	hw2_kobject = kobject_create_and_add("hw2", kernel_kobj);
	sysfs_create_file(hw2_kobject, &mailbox_attribute.attr);
	return 0;
}

static void __exit mailbox_exit(void)
{
	printk("Remove\n");
	kobject_put(hw2_kobject);
}

module_init(mailbox_init);
module_exit(mailbox_exit);
