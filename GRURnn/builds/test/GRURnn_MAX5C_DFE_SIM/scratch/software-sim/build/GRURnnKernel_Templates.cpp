#include "stdsimheader.h"

using namespace maxcompilersim;

namespace maxcompilersim {
// Templated Types used in the kernel
template class HWOffsetFix<17,0,UNSIGNED>;
template class HWOffsetFix<48,0,UNSIGNED>;
template class HWFloat<8,24>;
template class HWOffsetFix<49,0,UNSIGNED>;
template class HWOffsetFix<7,0,UNSIGNED>;
template class HWOffsetFix<5,0,UNSIGNED>;
template class HWOffsetFix<16,0,UNSIGNED>;
template class HWOffsetFix<6,0,UNSIGNED>;
template class HWOffsetFix<1,0,UNSIGNED>;
// add. templates from the default formatter 


// Templated Methods/Functions
template HWOffsetFix<6,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<6,0,UNSIGNED> >(const std::string &name);
template HWOffsetFix<17,0,UNSIGNED>add_fixed <17,0,UNSIGNED,TRUNCATE,17,0,UNSIGNED,17,0,UNSIGNED, false>(const HWOffsetFix<17,0,UNSIGNED> &a, const HWOffsetFix<17,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWOffsetFix<7,0,UNSIGNED>add_fixed <7,0,UNSIGNED,TRUNCATE,7,0,UNSIGNED,7,0,UNSIGNED, false>(const HWOffsetFix<7,0,UNSIGNED> &a, const HWOffsetFix<7,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWOffsetFix<1,0,UNSIGNED>gt_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWFloat<8,24>sub_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWFloat<8,24>add_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWOffsetFix<5,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<5,0,UNSIGNED> >(const std::string &name);
template HWOffsetFix<17,0,UNSIGNED> cast_fixed2fixed<17,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<16,0,UNSIGNED> &a);
template HWOffsetFix<6,0,UNSIGNED>sub_fixed <6,0,UNSIGNED,TONEAREVEN,6,0,UNSIGNED,6,0,UNSIGNED, false>(const HWOffsetFix<6,0,UNSIGNED> &a, const HWOffsetFix<6,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWOffsetFix<1,0,UNSIGNED>lt_fixed<>(const HWOffsetFix<6,0,UNSIGNED> &a, const HWOffsetFix<6,0,UNSIGNED> &b );
template HWOffsetFix<1,0,UNSIGNED>not_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a );
template HWOffsetFix<1,0,UNSIGNED>eq_fixed<>(const HWOffsetFix<16,0,UNSIGNED> &a, const HWOffsetFix<16,0,UNSIGNED> &b );
template HWOffsetFix<5,0,UNSIGNED> cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(const HWOffsetFix<6,0,UNSIGNED> &a);
template HWOffsetFix<16,0,UNSIGNED> cast_fixed2fixed<16,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<17,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED>lte_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWOffsetFix<1,0,UNSIGNED>eq_fixed<>(const HWOffsetFix<48,0,UNSIGNED> &a, const HWOffsetFix<48,0,UNSIGNED> &b );
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<17,0,UNSIGNED> &a, const HWOffsetFix<17,0,UNSIGNED> &b );
template HWFloat<8,24> KernelManagerBlockSync::readInput< HWFloat<8,24> >(const t_port_number port_number);
template void KernelManagerBlockSync::writeOutput< HWFloat<8,24> >(const t_port_number port_number, const HWFloat<8,24> &value);
template HWOffsetFix<6,0,UNSIGNED> cast_fixed2fixed<6,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<7,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<1,0,UNSIGNED> >(const std::string &name);
template HWOffsetFix<48,0,UNSIGNED> KernelManagerBlockSync::getMappedRegValue< HWOffsetFix<48,0,UNSIGNED> >(const std::string &name);
template void KernelManagerBlockSync::setMappedRegValue< HWOffsetFix<48,0,UNSIGNED> >(const std::string &name, const HWOffsetFix<48,0,UNSIGNED> & value);
template HWFloat<8,24>mul_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<49,0,UNSIGNED> &a, const HWOffsetFix<49,0,UNSIGNED> &b );
template HWOffsetFix<48,0,UNSIGNED> cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>(const HWOffsetFix<49,0,UNSIGNED> &a);
template HWOffsetFix<1,0,UNSIGNED>gte_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWOffsetFix<49,0,UNSIGNED>add_fixed <49,0,UNSIGNED,TRUNCATE,49,0,UNSIGNED,49,0,UNSIGNED, false>(const HWOffsetFix<49,0,UNSIGNED> &a, const HWOffsetFix<49,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWOffsetFix<1,0,UNSIGNED>gte_fixed<>(const HWOffsetFix<7,0,UNSIGNED> &a, const HWOffsetFix<7,0,UNSIGNED> &b );
template HWOffsetFix<1,0,UNSIGNED>eq_fixed<>(const HWOffsetFix<6,0,UNSIGNED> &a, const HWOffsetFix<6,0,UNSIGNED> &b );
template HWOffsetFix<1,0,UNSIGNED>gt_fixed<>(const HWOffsetFix<6,0,UNSIGNED> &a, const HWOffsetFix<6,0,UNSIGNED> &b );
template HWOffsetFix<16,0,UNSIGNED>sub_fixed <16,0,UNSIGNED,TONEAREVEN,16,0,UNSIGNED,16,0,UNSIGNED, false>(const HWOffsetFix<16,0,UNSIGNED> &a, const HWOffsetFix<16,0,UNSIGNED> &b , EXCEPTOVERFLOW);
template HWOffsetFix<1,0,UNSIGNED>lt_float<>(const HWFloat<8,24> &a, const HWFloat<8,24> &b );
template HWOffsetFix<1,0,UNSIGNED>and_fixed<>(const HWOffsetFix<1,0,UNSIGNED> &a, const HWOffsetFix<1,0,UNSIGNED> &b );


// Additional Code
std::string GRURnnKernel::format_string_GRURnnKernel_1 (const char* _format_arg_format_string)
{return ( bfmt(_format_arg_format_string)).str();}
std::string GRURnnKernel::format_string_GRURnnKernel_2 (const char* _format_arg_format_string)
{return ( bfmt(_format_arg_format_string)).str();}
std::string GRURnnKernel::format_string_GRURnnKernel_3 (const char* _format_arg_format_string)
{return ( bfmt(_format_arg_format_string)).str();}

} // End of maxcompilersim namespace
