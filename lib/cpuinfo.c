#include "cpuinfo.h"

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
	cpuinfo->version_information.family_id = (registers->eax >> 8) & 0xf;
	cpuinfo->version_information.processor_type = (registers->eax >> 12) & 0xf;
	cpuinfo->version_information.extended_model_id = (registers->eax >> 16) & 0xf;
	cpuinfo->version_information.extended_family_id = (registers->eax >> 20) & 0xf;

	if(cpuinfo->version_information.family_id == 0xf)
		cpuinfo->version_information.family_id += cpuinfo->version_information.extended_family_id;

	if(cpuinfo->version_information.family_id == 0x6 || cpuinfo->version_information.family_id == 0xf)
		cpuinfo->version_information.model = (cpuinfo->version_information.extended_model_id << 4) + cpuinfo->version_information.model;
}
void load_struct(struct cpuid* cpuinfo, struct reg_struct* registers){
	inline_cpuid(0,registers);
	fill_cpuinfo0x0(cpuinfo,registers);
	inline_cpuid(1,registers);
	fill_cpuinfo0x1(cpuinfo,registers);
}
