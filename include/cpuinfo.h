#ifndef _CPUINFO_H
#define _CPUINFO_H

#include <stdint.h>

typedef struct cpuid{
	struct {
		uint32_t maximum_value;
		uint32_t string[4];
	} basic_info;

	struct {
		unsigned int stepping_id 	: 4;
		unsigned int model 		: 4;
		unsigned int family_id 		: 4;
		unsigned int processor_type 	: 2;
		unsigned int extended_model_id 	: 4;
	       	unsigned int extended_family_id : 4;
	} version_information;

}cpuid;

typedef struct reg_struct{
	uint32_t eax;
	uint32_t ebx;
	uint32_t ecx;
	uint32_t edx;
}reg_struct;

void inline_cpuid(int32_t value, struct reg_struct* registers);

/* Basic CPU Information */
void fill_cpuinfo0x0(struct cpuid* cpuinfo, struct reg_struct* registers);

void fill_cpuinfo0x1(struct cpuid* cpuinfo, struct reg_struct* registers);

void load_struct(struct cpuid* cpuinfo, struct reg_struct* registers);
#endif
