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
		unsigned int reserved_1		: 2;
		unsigned int extended_model_id 	: 4;
	       	unsigned int extended_family_id : 4;
		unsigned int brand_index	: 4;
		unsigned int clflush_line_size	: 8;
		unsigned int max_number_ids	: 8;
		unsigned int initial_apic_id	: 8;
		unsigned int reserved_2		: 4;
	} version_information;

	struct {
		unsigned int sse3	  : 1;
		unsigned int pclmulqdq	  : 1;
		unsigned int dtes64	  : 1;
		unsigned int monitor	  : 1;
		unsigned int ds_cpl	  : 1;
		unsigned int vmx	  : 1;
		unsigned int smx	  : 1;
		unsigned int eist	  : 1;
		unsigned int tm2	  : 1;
		unsigned int ssse3	  : 1;
		unsigned int cnxt_id	  : 1;
		unsigned int sdbg	  : 1;
		unsigned int fma	  : 1;
		unsigned int cmpxchg16b   : 1;
		unsigned int xtpr	  : 1;
		unsigned int pdcm	  : 1;
		unsigned int reserved	  : 1;
		unsigned int pcid	  : 1;
		unsigned int dca	  : 1;
		unsigned int sse4_1	  : 1;
		unsigned int sse4_2	  : 1;
		unsigned int x2apic	  : 1;
		unsigned int movbe	  : 1;
		unsigned int popcnt	  : 1;
		unsigned int tsc_deadline : 1;
		unsigned int aesni	  : 1;
		unsigned int xsave	  : 1;
		unsigned int osxsave	  : 1;
		unsigned int avx	  : 1;
		unsigned int f16c	  : 1;
		unsigned int rdrand	  : 1;
		unsigned int not_used	  : 1;
		unsigned int fpu	  : 1;
		unsigned int vme	  : 1;
		unsigned int de		  : 1;
		unsigned int pse	  : 1;
		unsigned int tsc	  : 1;
		unsigned int msr	  : 1;
		unsigned int pae	  : 1;
		unsigned int mce	  : 1;
		unsigned int cx8	  : 1;
		unsigned int apic	  : 1;
		unsigned int reserved_1	  : 1;
		unsigned int sep	  : 1;
		unsigned int mtrr	  : 1;
		unsigned int pge	  : 1;
		unsigned int mca	  : 1;
		unsigned int cmov	  : 1;
		unsigned int pat	  : 1;
		unsigned int pse_36	  : 1;
		unsigned int psn	  : 1;
		unsigned int clfsh	  : 1;
		unsigned int reserved_2	  : 1;
		unsigned int ds		  : 1;
		unsigned int acpi	  : 1;
		unsigned int mmx	  : 1;
		unsigned int fxsr	  : 1;
		unsigned int sse	  : 1;
		unsigned int sse2	  : 1;
		unsigned int ss		  : 1;
		unsigned int htt	  : 1;
		unsigned int tm		  : 1;
		unsigned int reserved_3	  : 1;
		unsigned int pbe	  : 1;
	} features_cpu;

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
