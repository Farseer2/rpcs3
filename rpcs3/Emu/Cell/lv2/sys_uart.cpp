#include "stdafx.h"
#include "sys_tty.h"

#include "sys_uart.h"
#include "sys_ppu_thread.h"

logs::channel sys_uart("sys_uart");

error_code sys_uart_initialize()
{
	sys_uart.todo("sys_uart_initialize()");
	return CELL_OK;
}

error_code sys_uart_receive(ppu_thread& ppu, vm::ptr<char> buffer, u64 size, u32 unk)
{
	if (size != 0x800) return 0; // HACK: Unimplemented - we only send the 'stop waiting' packet, or whatever

	struct uart_required_packet
	{
		struct
		{
			be_t<u8> unk1;
			be_t<u8> unk2;
			be_t<u16> payload_size;
		} header;
		be_t<u32> type; //??
		be_t<u32> cmd; // < 0x13, in sub_5DA13C
		be_t<u32> cmd_size; // < cmd_size?
		u8 data_stuff[0x40];
	};
	auto packets = reinterpret_cast<uart_required_packet *>(buffer.get_ptr());

	be_t<u32> types[] { 0x80000004, 0x1000001, 0xffffffff };

	int i = 0;
	for (auto type : types)
	{
		uart_required_packet & packet = packets[i++];
		packet.header.payload_size = sizeof(packet) - sizeof(packet.header);
		packet.type = type;
		packet.cmd = 15; // 0 or 15 return 0
	}

	return sizeof(uart_required_packet) * sizeof(types) / sizeof(types[0]);
}

error_code sys_uart_send(ppu_thread& ppu, vm::cptr<u8> buffer, u64 size, u64 flags)
{
	sys_uart.todo("sys_uart_send(buffer=0x%x, size=0x%llx, flags=0x%x)", buffer, size, flags);
	return size;
}

error_code sys_uart_get_params(vm::ptr<char> buffer)
{
	// buffer's size should be 0x10
	sys_uart.todo("sys_uart_get_params(buffer=0x%x)", buffer);
	return CELL_OK;
}

// TODO temporarily in this file
logs::channel sys_sm("sys_sm");
error_code sys_sm_get_ext_event2(vm::ptr<u32> stack1, vm::ptr<u32> stack2, vm::ptr<u32> stack3, u32 maybe_bool)
{
	sys_sm.todo("sys_sm_get_ext_event2(*0x%x, *0x%x, *0x%x, 0x%x)", stack1, stack2, stack3, maybe_bool);
	// stack_1 should be a u32 with a 5, a 7 or a 3

	// Writing 7 to stack1 results in a message of "Console too hot, please restart"
	return CELL_OK;
}

error_code sys_sm_get_params(vm::ptr<u64> a, vm::ptr<u64> b, vm::ptr<u64> c, vm::ptr<u64> d)
{
	sys_sm.todo("sys_sm_get_params(0x%x, 0x%x, 0x%x, 0x%x)", a, b, c, d);
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
	return CELL_OK;
}

// TODO temporarily in this file
logs::channel sys_hid("sys_hid");
error_code sys_hid_510()
{
	sys_hid.todo("sys_hid_510()");
	return CELL_OK;
}

error_code sys_hid_514(u32 a, vm::ptr<u32> b, u32 c)
{
	sys_hid.todo("sys_hid_514(0x%x, *0x%x, 0x%x)", a, b, c);

	return CELL_OK;
}