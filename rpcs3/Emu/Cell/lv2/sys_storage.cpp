#include "stdafx.h"
#include "Emu/Memory/Memory.h"
#include "Emu/System.h"

#include "Emu/Cell/ErrorCodes.h"
#include "sys_usbd.h"

logs::channel sys_storage("sys_storage");

s32 sys_storage_open(u64 device, u32 mode, vm::ptr<u32> fd, u32 flags)
{
	sys_storage.todo("sys_storage_open(device=0x%x, mode=0x%x, fd=*0x%x, 0x%x)", device, mode, fd, flags);
	*fd = 0xdadad0d0; // Poison value
	return CELL_OK;
}

s32 sys_storage_close(u32 fd)
{
	sys_storage.todo("sys_storage_close(fd=0x%x)", fd);
	return CELL_OK;
}

s32 sys_storage_read(u32 fd, u32 mode, u32 start_sector, u32 num_sectors, vm::ptr<u8> bounce_buf, vm::ptr<u32> sectors_read, u64 flags)
{
	sys_storage.todo("sys_storage_read(fd=0x%x, mode=0x%x, start_sector=0x%x, num_sectors=0x%x, bounce_buf=*0x%x, sectors_read=*0x%x, flags=0x%x)", fd, mode, start_sector, num_sectors, bounce_buf, sectors_read, flags);
	*sectors_read = num_sectors; // LIESSSSS!
	memset(bounce_buf.get_ptr(), 0, num_sectors * 0x10000);
	return CELL_OK;
}

s32 sys_storage_write()
{
	sys_storage.todo("sys_storage_write()");
	return CELL_OK;
}

s32 sys_storage_send_device_command()
{
	sys_storage.todo("sys_storage_send_device_command()");
	return CELL_OK;
}

s32 sys_storage_async_configure()
{
	sys_storage.todo("sys_storage_async_configure()");
	return CELL_OK;
}

s32 sys_storage_async_read()
{
	sys_storage.todo("sys_storage_async_read()");
	return CELL_OK;
}

s32 sys_storage_async_write()
{
	sys_storage.todo("sys_storage_async_write()");
	return CELL_OK;
}

s32 sys_storage_async_cancel()
{
	sys_storage.todo("sys_storage_async_cancel()");
	return CELL_OK;
}

s32 sys_storage_get_device_info(u64 device, vm::ptr<u8> buffer)
{
	sys_storage.todo("sys_storage_get_device_info(device=0x%x, config=0x%x)", device, buffer);
	//*reinterpret_cast<be_t<u64>*>(buffer.get_ptr() + 0x28) = 0x0909090909090909; // sector count?
	*reinterpret_cast<be_t<u32>*>(buffer.get_ptr() + 0x30) = 0x1; // Functions tries to allocate (this size + 0xfffffffff) >> 20
	buffer[0x35] = 1; // writable?
	buffer[0x3f] = 1;
	buffer[0x39] = 1;
	buffer[0x3a] = 1;
	return CELL_OK;
}

s32 sys_storage_get_device_config(u64 device, vm::ptr<u32> count)
{
	sys_storage.todo("sys_storage_get_device_config(device=*0x%x, count=0x%x)", device, count);


	*count = 1;

	return CELL_OK;
}

s32 sys_storage_report_devices(vm::ptr<void> a, u32 b, u32 count, vm::ptr<u64> device_ids)
{
	sys_storage.todo("sys_storage_report_devices(0x%x, 0x%x, count=0x%x, device_ids=0x%x)", a, b, count, device_ids);
	*device_ids = 0x101000000000007;
	return CELL_OK;
}

s32 sys_storage_configure_medium_event(u32 fd, u32 equeue_id, u32 c)
{
	sys_storage.todo("sys_storage_configure_medium_event(fd=0x%x, equeue_id=0x%x, 0x%x)", fd, equeue_id, c);
	return CELL_OK;
}

s32 sys_storage_set_medium_polling_interval()
{
	sys_storage.todo("sys_storage_set_medium_polling_interval()");
	return CELL_OK;
}

s32 sys_storage_create_region()
{
	sys_storage.todo("sys_storage_create_region()");
	return CELL_OK;
}

s32 sys_storage_delete_region()
{
	sys_storage.todo("sys_storage_delete_region()");
	return CELL_OK;
}

s32 sys_storage_execute_device_command(u32 fd, u64 cmd, vm::ptr<char> cmdbuf, u64 cmdbuf_size, vm::ptr<char> databuf, u64 databuf_size, vm::ptr<u32> driver_status)
{
	sys_storage.todo("sys_storage_execute_device_command(fd=0x%x, cmd=0x%x, cmdbuf=*0x%x, cmdbuf_size=0x%x, databuf=*0x%x, databuf_size=0x%x, driver_status=*0x%x)", fd, cmd, cmdbuf, cmdbuf_size, databuf, databuf_size, driver_status);
	return CELL_OK;
}

s32 sys_storage_check_region_acl()
{
	sys_storage.todo("sys_storage_check_region_acl()");
	return CELL_OK;
}

s32 sys_storage_set_region_acl()
{
	sys_storage.todo("sys_storage_set_region_acl()");
	return CELL_OK;
}

s32 sys_storage_async_send_device_command()
{
	sys_storage.todo("sys_storage_async_send_device_command()");
	return CELL_OK;
}

s32 sys_storage_get_region_offset()
{
	sys_storage.todo("sys_storage_get_region_offset()");
	return CELL_OK;
}

s32 sys_storage_set_emulated_speed()
{
	sys_storage.todo("sys_storage_set_emulated_speed()");
	return CELL_OK;
}
