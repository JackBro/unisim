#ifndef SIM_H
#define SIM_H
#include "loader.h"
#include <stdint.h>

typedef enum { D_IMM_SH_INST, D_REG_SH_INST, MUL_INST, BRX_INST, SDT_INST, ST_INST,
			   BRLK_INST, LSI_OFFSET_INST, LSHWI_OFFSET_INST } inst_type_t;
typedef struct {
	uint32_t rm:5;
	uint32_t b5:1;
	uint32_t shift:2;
	uint32_t b8:1;
	uint32_t shift_imm:5;
	uint32_t rd:5;
	uint32_t rn:5;
	uint32_t S:1;
	uint32_t opcode:4;
	uint32_t b29:1;
	uint32_t b30:1;
	uint32_t b31:1;
} d_imm_sh_inst_t;

typedef struct {
	uint32_t rm:5;
	uint32_t b5:1;
	uint32_t shift:2;
	uint32_t b8:1;
	uint32_t rs:5;
	uint32_t rd:5;
	uint32_t rn:5;
	uint32_t S:1;
	uint32_t opcode:4;
	uint32_t b29:1;
	uint32_t b30:1;
	uint32_t b31:1;
} d_reg_sh_inst_t;

typedef struct {
	uint32_t rm:5;
	uint32_t b5:1;
	uint32_t b6:1;
	uint32_t b7:1;
	uint32_t b8:1;
	uint32_t rs:5;
	uint32_t rd:5;
	uint32_t rn:5;
	uint32_t S:1;
	uint32_t A:1;
	uint32_t b26:1;
	uint32_t b27:1;
	uint32_t b28:1;
	uint32_t b29:1;
	uint32_t b30:1;
	uint32_t b31:1;
} mul_inst_t;

typedef struct {
	uint32_t rm:5;
	uint32_t bleft1:19;
	uint32_t L:1;
	uint32_t bleft2:7;
} brx_inst_t;

typedef struct {
	uint32_t imm:9;
	uint32_t rotate:5;
	uint32_t rd:5;
	uint32_t rn:5;
	uint32_t S:1;
	uint32_t opcode:4;
	uint32_t b29:1;
	uint32_t b30:1;
	uint32_t b31:1;
} d_imm_inst_t;

typedef struct {
	uint32_t rm:5;
	uint32_t b5:1;
	uint32_t shift:2;
	uint32_t b8:1;
	uint32_t shift_imm:5;
	uint32_t rd:5;
	uint32_t rn:5;
	uint32_t L:1;
	uint32_t W:1;
	uint32_t B:1;
	uint32_t U:1;
	uint32_t P:1;
	uint32_t b29:1;
	uint32_t b30:1;
	uint32_t b31:1;
} lsr_offset_inst_t;

typedef struct {
	uint32_t rm:5;
	uint32_t b5:1;
	uint32_t H:1;
	uint32_t S:1;
	uint32_t b8:1;
	uint32_t shift_imm:5;
	uint32_t rd:5;
	uint32_t rn:5;
	uint32_t L:1;
	uint32_t W:1;
	uint32_t B:1;
	uint32_t U:1;
	uint32_t P:1;
	uint32_t b29:1;
	uint32_t b30:1;
	uint32_t b31:1;
} lshwr_offset_inst_t;

typedef struct {
	uint32_t loffset:5;
	uint32_t b5:1;
	uint32_t H:1;
	uint32_t S:1;
	uint32_t b8:1;
	uint32_t hoffset:5;
	uint32_t rd:5;
	uint32_t rn:5;
	uint32_t L:1;
	uint32_t W:1;
	uint32_t B:1;
	uint32_t U:1;
	uint32_t P:1;
	uint32_t b29:1;
	uint32_t b30:1;
	uint32_t b31:1;
} lshwi_offset_inst_t;

typedef struct {
	uint32_t himm:14;
	uint32_t rd:5;
	uint32_t rn:5;
	uint32_t L:1;
	uint32_t W:1;
	uint32_t I:1;
	uint32_t U:1;
	uint32_t P:1;
	uint32_t b29:1;
	uint32_t b30:1;
	uint32_t b31:1;
} lsi_offset_inst_t;

typedef struct {
	uint32_t offset:24;
	uint32_t L:1;
	uint32_t cond:4;
	uint32_t b29:1;
	uint32_t b30:1;
	uint32_t b31:1;
} brlk_inst_t;

typedef struct {
	uint32_t offset:24;
	uint32_t bleft:8;
} st_inst_t;

typedef struct {
	uint32_t N:1;
	uint32_t Z:1;
	uint32_t C:1;
	uint32_t V:1;
	uint32_t unused:20;
	uint32_t I:1;
	uint32_t F:1;
	uint32_t T:1;
	uint32_t mode:5;
} stat_reg_t;

typedef struct {
	inst_type_t inst_type;
} inst_t;

#define REG_NUM 33

extern int pc;
extern int regs[REG_NUM];

int simulate(int entry);

int fetch(inst_t *inst);

int decode(inst_t *inst);

int execute(inst_t *inst);

int memory(inst_t *inst);

int writeback(inst_t *inst);
#endif
