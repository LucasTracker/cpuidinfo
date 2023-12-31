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
	cpuinfo->version_information.stepping_id = registers->eax & 0xff;
	cpuinfo->version_information.model = (registers->eax >> 4) & 0xff;
	cpuinfo->version_information.family_id = (registers->eax >> 8) & 0xff;
	cpuinfo->version_information.processor_type = (registers->eax >> 12) & 0xff;
	cpuinfo->version_information.extended_model_id = (registers->eax >> 16) & 0xff;
	cpuinfo->version_information.extended_family_id = (registers->eax >> 20) & 0xff;
	cpuinfo->version_information.brand_index = registers->ebx & 0xff;
	cpuinfo->version_information.clflush_line_size = ((registers->ebx >> 8) & 0xff) * 8;
	cpuinfo->version_information.max_number_ids = (registers->ebx >> 16) & 0xff;
	cpuinfo->version_information.initial_apic_id = (registers->ebx >> 24) & 0xff;


	if(cpuinfo->version_information.family_id == 0xf)
		cpuinfo->version_information.family_id += cpuinfo->version_information.extended_family_id;

	if(cpuinfo->version_information.family_id == 0x6 || cpuinfo->version_information.family_id == 0xf)
		cpuinfo->version_information.model = (cpuinfo->version_information.extended_model_id << 4) + cpuinfo->version_information.model;

	//Features ECX
	
	cpuinfo->features_cpu.sse3 = registers->ecx & 0x1;
	cpuinfo->features_cpu.pclmulqdq = (registers->ecx >> 1) & 0x1;
	cpuinfo->features_cpu.dtes64 = (registers->ecx >> 2) & 0x1;
	cpuinfo->features_cpu.monitor = (registers->ecx >> 3) & 0x1;
	cpuinfo->features_cpu.ds_cpl = (registers->ecx >> 4) & 0x1;
	cpuinfo->features_cpu.vmx = (registers->ecx >> 5) & 0x1;
	cpuinfo->features_cpu.smx = (registers->ecx >> 6) & 0x1;
	cpuinfo->features_cpu.eist = (registers->ecx >> 7) & 0x1;
	cpuinfo->features_cpu.tm2 = (registers->ecx >> 8) & 0x1;
	cpuinfo->features_cpu.ssse3 = (registers->ecx >> 9) & 0x1;
	cpuinfo->features_cpu.cnxt_id = (registers->ecx >> 10) & 0x1;
	cpuinfo->features_cpu.sdbg = (registers->ecx >> 11) & 0x1;
	cpuinfo->features_cpu.fma = (registers->ecx >> 12) & 0x1;
	cpuinfo->features_cpu.cmpxchg16b = (registers->ecx >> 13) & 0x1;
	cpuinfo->features_cpu.xtpr = (registers->ecx >> 14) & 0x1;
	cpuinfo->features_cpu.pdcm = (registers->ecx >> 15) & 0x1;
	cpuinfo->features_cpu.reserved = (registers->ecx >> 16) & 0x1;
	cpuinfo->features_cpu.pcid = (registers->ecx >> 17) & 0x1;
	cpuinfo->features_cpu.dca = (registers->ecx >> 18) & 0x1;
	cpuinfo->features_cpu.sse4_1 = (registers->ecx >> 19) & 0x1;
	cpuinfo->features_cpu.sse4_2 = (registers->ecx >> 20) & 0x1;
	cpuinfo->features_cpu.x2apic = (registers->ecx >> 21) & 0x1;
	cpuinfo->features_cpu.movbe = (registers->ecx >> 22) & 0x1;
	cpuinfo->features_cpu.popcnt = (registers->ecx >> 23) & 0x1;
	cpuinfo->features_cpu.tsc_deadline = (registers->ecx >> 24) & 0x1;
	cpuinfo->features_cpu.aesni = (registers->ecx >> 25) & 0x1;
	cpuinfo->features_cpu.xsave = (registers->ecx >> 27) & 0x1;
	cpuinfo->features_cpu.osxsave = (registers->ecx >> 28) & 0x1;
	cpuinfo->features_cpu.avx = (registers->ecx >> 29) & 0x1;
	cpuinfo->features_cpu.f16c = (registers->ecx >> 30) & 0x1;
	cpuinfo->features_cpu.rdrand = (registers->ecx >> 31 )& 0x1;

	// Features EDX
	
	cpuinfo->features_cpu.fpu = registers->edx & 0x1;
	cpuinfo->features_cpu.vme = (registers->edx >> 1) & 0x1;
	cpuinfo->features_cpu.de = (registers->edx >> 2) & 0x1;
	cpuinfo->features_cpu.pse = (registers->edx >> 3) & 0x1;
	cpuinfo->features_cpu.tsc = (registers->edx >> 4) & 0x1;
	cpuinfo->features_cpu.msr = (registers->edx >> 5) & 0x1;
	cpuinfo->features_cpu.pae = (registers->edx >> 6) & 0x1;
	cpuinfo->features_cpu.mce = (registers->edx >> 7) & 0x1;
	cpuinfo->features_cpu.cx8 = (registers->edx >> 8) & 0x1;
	cpuinfo->features_cpu.apic = (registers->edx >> 9) & 0x1;
	cpuinfo->features_cpu.reserved_1 = (registers->edx >> 10) & 0x1;
	cpuinfo->features_cpu.sep = (registers->edx >> 11) & 0x1;
	cpuinfo->features_cpu.mtrr = (registers->edx >> 12) & 0x1;
	cpuinfo->features_cpu.pge = (registers->edx >> 13) & 0x1;
	cpuinfo->features_cpu.mca = (registers->edx >> 14) & 0x1;
	cpuinfo->features_cpu.cmov = (registers->edx >> 15) & 0x1;
	cpuinfo->features_cpu.pat = (registers->edx >> 16) & 0x1;
	cpuinfo->features_cpu.pse_36 = (registers->edx >> 17) & 0x1;
	cpuinfo->features_cpu.psn = (registers->edx >> 18) & 0x1;
	cpuinfo->features_cpu.clfsh = (registers->edx >> 19) & 0x1;
	cpuinfo->features_cpu.reserved_2 = (registers->edx >> 20) & 0x1;
	cpuinfo->features_cpu.ds = (registers->edx >> 21) & 0x1;
	cpuinfo->features_cpu.acpi = (registers->edx >> 22) & 0x1;
	cpuinfo->features_cpu.mmx = (registers->edx >> 23) & 0x1;
	cpuinfo->features_cpu.fxsr = (registers->edx >> 24) & 0x1;
	cpuinfo->features_cpu.sse = (registers->edx >> 25) & 0x1;
	cpuinfo->features_cpu.sse2 = (registers->edx >> 26) & 0x1;
	cpuinfo->features_cpu.ss = (registers->edx >> 27) & 0x1;
	cpuinfo->features_cpu.htt = (registers->edx >> 28) & 0x1;
	cpuinfo->features_cpu.tm = (registers->edx >> 29) & 0x1;
	cpuinfo->features_cpu.reserved_3 = (registers->edx >> 30) & 0x1;
	cpuinfo->features_cpu.pbe = (registers->edx >> 31) & 0x1;

}
void load_struct(struct cpuid* cpuinfo, struct reg_struct* registers){
	inline_cpuid(0,registers);
	fill_cpuinfo0x0(cpuinfo,registers);
	inline_cpuid(1,registers);
	fill_cpuinfo0x1(cpuinfo,registers);
}
