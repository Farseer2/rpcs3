#pragma once

// SysCalls
s32 sys_storage_open(u64 device, u32 b, vm::ptr<u32> fd, u32 d);
s32 sys_storage_close(u32 fd);
s32 sys_storage_read(u32 fd, u32 mode, u32 start_sector, u32 num_sectors, vm::ptr<u8> bounce_buf, vm::ptr<u32> sectors_read, u64 flags);
s32 sys_storage_write();
s32 sys_storage_send_device_command();
s32 sys_storage_async_configure();
s32 sys_storage_async_read();
s32 sys_storage_async_write();
s32 sys_storage_async_cancel();
s32 sys_storage_get_device_info(u64 device, vm::ptr<u8> buffer);
s32 sys_storage_get_device_config(u64 device, vm::ptr<u32> count);
s32 sys_storage_report_devices(vm::ptr<void> a, u32 b, u32 count, vm::ptr<u64> device_ids);
s32 sys_storage_configure_medium_event(u32 fd, u32 equeue_id, u32 c);
s32 sys_storage_set_medium_polling_interval();
s32 sys_storage_create_region();
s32 sys_storage_delete_region();
s32 sys_storage_execute_device_command(u32 fd, u64 cmd, vm::ptr<char> cmdbuf, u64 cmdbuf_size, vm::ptr<char> databuf, u64 databuf_size, vm::ptr<u32> driver_status);
s32 sys_storage_check_region_acl();
s32 sys_storage_set_region_acl();
s32 sys_storage_async_send_device_command();
s32 sys_storage_get_region_offset();
s32 sys_storage_set_emulated_speed();