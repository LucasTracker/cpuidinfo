#ifndef _CPUINFO_H
#define _CPUINFO_H

#include <stdint.h>

struct cpuid{
	struct {
		uint32_t maximum_value;
		uint32_t string[4];
	} basic_info;

	struct {
		unsigned int stepping_id : 4;
		unsigned int model : 4;
		unsigned int family_id : 4;
	} version_information;

}cpuinfo;

struct reg_struct{
	uint32_t eax;
	uint32_t ebx;
	uint32_t ecx;
	uint32_t edx;
}registers;

void inline_cpuid(int32_t value, struct reg_struct* registers){
	__asm__ __volatile__("cpuid" : "=a" (registers->eax), "=b" (registers->ebx) , "=c" (registers->ecx) , "=d" (registers->edx) : "0" (value));
}

/* Basic CPU Information */
void fill_cpuinfo0x0(struct cpuid* cpuinfo, struct reg_struct* registers){
	cpuinfo->basic_info.maximum_value = registers->eax;
	cpuinfo->basic_info.string[0] = registers->ebx;
	cpuinfo->basic_info.string[1] = registers->edx;
	cpuinfo->basic_info.string[2] = registers->ecx;
	cpuinfo->basic_info.string[3] = '\0';
}


void fill_cpuinfo0x1(struct cpuid* cpuinfo, struct reg_struct* registers){
	cpuinfo->version_information.stepping_id = registers->eax & 0xf;
	cpuinfo->version_information.model = (registers->eax >> 4) & 0xf;
	cpuinfo->version_information.family_id = (registers->eax >> 8) &0xf;
}
void load_struct(struct cpuid* cpuinfo, struct reg_struct* registers){
	inline_cpuid(0,registers);
	fill_cpuinfo0x0(cpuinfo,registers);
	inline_cpuid(1,registers);
	fill_cpuinfo0x1(cpuinfo,registers);
}
#endif
