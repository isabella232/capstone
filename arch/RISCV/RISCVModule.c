/* Capstone Disassembly Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2013-2014 */

#ifdef CAPSTONE_HAS_RISCV

#include "../../utils.h"
#include "../../MCRegisterInfo.h"
#include "RISCVDisassembler.h"
#include "RISCVInstPrinter.h"
#include "RISCVMapping.h"
#include "RISCVModule.h"

cs_err RISCV_global_init(cs_struct *ud)
{
	MCRegisterInfo *mri;
	mri = cs_mem_malloc(sizeof(*mri));

	RISCV_init(mri);
	ud->printer = RISCV_printInst;
	ud->printer_info = mri;
	ud->getinsn_info = mri;
	ud->disasm = RISCV_getInstruction;
	ud->post_printer = RISCV_post_printer;

	ud->reg_name = RISCV_reg_name;
	ud->insn_id = RISCV_get_insn_id;
	ud->insn_name = RISCV_insn_name;
	ud->group_name = RISCV_group_name;

	return CS_ERR_OK;
}

cs_err RISCV_option(cs_struct *handle, cs_opt_type type, size_t value)
{
	if (type == CS_OPT_SYNTAX)
		handle->syntax = (int) value;

	if (type == CS_OPT_MODE) {
		handle->mode = (cs_mode)value;
	}

	return CS_ERR_OK;
}

static void destroy(cs_struct *handle)
{
}

#endif