#include "stdsimheader.h"

namespace maxcompilersim {

void GRURnnKernel::execute0() {
  { // Node ID: 3 (NodeConstantRawBits)
  }
  { // Node ID: 790 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 8 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id8in_enable = id3out_value;
    const HWOffsetFix<16,0,UNSIGNED> &id8in_max = id790out_value;

    HWOffsetFix<17,0,UNSIGNED> id8x_1;
    HWOffsetFix<1,0,UNSIGNED> id8x_2;
    HWOffsetFix<1,0,UNSIGNED> id8x_3;
    HWOffsetFix<17,0,UNSIGNED> id8x_4t_1e_1;

    id8out_count = (cast_fixed2fixed<16,0,UNSIGNED,TRUNCATE>((id8st_count)));
    (id8x_1) = (add_fixed<17,0,UNSIGNED,TRUNCATE>((id8st_count),(c_hw_fix_17_0_uns_bits_1)));
    (id8x_2) = (gte_fixed((id8x_1),(cast_fixed2fixed<17,0,UNSIGNED,TRUNCATE>(id8in_max))));
    (id8x_3) = (and_fixed((id8x_2),id8in_enable));
    id8out_wrap = (id8x_3);
    if((id8in_enable.getValueAsBool())) {
      if(((id8x_3).getValueAsBool())) {
        (id8st_count) = (c_hw_fix_17_0_uns_bits);
      }
      else {
        (id8x_4t_1e_1) = (id8x_1);
        (id8st_count) = (id8x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 549 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 7 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id7in_enable = id8out_wrap;
    const HWOffsetFix<7,0,UNSIGNED> &id7in_max = id549out_value;

    HWOffsetFix<7,0,UNSIGNED> id7x_1;
    HWOffsetFix<1,0,UNSIGNED> id7x_2;
    HWOffsetFix<1,0,UNSIGNED> id7x_3;
    HWOffsetFix<7,0,UNSIGNED> id7x_4t_1e_1;

    id7out_count = (cast_fixed2fixed<6,0,UNSIGNED,TRUNCATE>((id7st_count)));
    (id7x_1) = (add_fixed<7,0,UNSIGNED,TRUNCATE>((id7st_count),(c_hw_fix_7_0_uns_bits_2)));
    (id7x_2) = (gte_fixed((id7x_1),id7in_max));
    (id7x_3) = (and_fixed((id7x_2),id7in_enable));
    id7out_wrap = (id7x_3);
    if((id7in_enable.getValueAsBool())) {
      if(((id7x_3).getValueAsBool())) {
        (id7st_count) = (c_hw_fix_7_0_uns_bits_1);
      }
      else {
        (id7x_4t_1e_1) = (id7x_1);
        (id7st_count) = (id7x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 612 (NodeFIFO)
    const HWOffsetFix<6,0,UNSIGNED> &id612in_input = id7out_count;

    id612out_output[(getCycle()+1)%2] = id612in_input;
  }
  { // Node ID: 0 (NodeInputMappedReg)
  }
  { // Node ID: 548 (NodeConstantRawBits)
  }
  { // Node ID: 403 (NodeSub)
    const HWOffsetFix<6,0,UNSIGNED> &id403in_a = id0out_hsize;
    const HWOffsetFix<6,0,UNSIGNED> &id403in_b = id548out_value;

    id403out_result[(getCycle()+1)%2] = (sub_fixed<6,0,UNSIGNED,TONEAREVEN>(id403in_a,id403in_b));
  }
  { // Node ID: 550 (NodeEqInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id550in_a = id612out_output[getCycle()%2];
    const HWOffsetFix<6,0,UNSIGNED> &id550in_b = id403out_result[getCycle()%2];

    id550out_result[(getCycle()+1)%2] = (eq_fixed(id550in_a,id550in_b));
  }
  { // Node ID: 613 (NodeFIFO)
    const HWOffsetFix<16,0,UNSIGNED> &id613in_input = id8out_count;

    id613out_output[(getCycle()+1)%2] = id613in_input;
  }
  { // Node ID: 547 (NodeConstantRawBits)
  }
  { // Node ID: 406 (NodeSub)
    const HWOffsetFix<16,0,UNSIGNED> &id406in_a = id790out_value;
    const HWOffsetFix<16,0,UNSIGNED> &id406in_b = id547out_value;

    id406out_result[(getCycle()+1)%2] = (sub_fixed<16,0,UNSIGNED,TONEAREVEN>(id406in_a,id406in_b));
  }
  { // Node ID: 551 (NodeEqInlined)
    const HWOffsetFix<16,0,UNSIGNED> &id551in_a = id613out_output[getCycle()%2];
    const HWOffsetFix<16,0,UNSIGNED> &id551in_b = id406out_result[getCycle()%2];

    id551out_result[(getCycle()+1)%2] = (eq_fixed(id551in_a,id551in_b));
  }
  { // Node ID: 408 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id408in_a = id550out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id408in_b = id551out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id408x_1;

    (id408x_1) = (and_fixed(id408in_a,id408in_b));
    id408out_result[(getCycle()+1)%2] = (id408x_1);
  }
  { // Node ID: 409 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id410out_result;

  { // Node ID: 410 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id410in_a = id409out_io_vecOutput_force_disabled;

    id410out_result = (not_fixed(id410in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id411out_result;

  { // Node ID: 411 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id411in_a = id408out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id411in_b = id410out_result;

    HWOffsetFix<1,0,UNSIGNED> id411x_1;

    (id411x_1) = (and_fixed(id411in_a,id411in_b));
    id411out_result = (id411x_1);
  }
  { // Node ID: 770 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id770in_input = id411out_result;

    id770out_output[(getCycle()+127)%128] = id770in_input;
  }
  { // Node ID: 546 (NodeConstantRawBits)
  }
  { // Node ID: 389 (NodeSub)
    const HWOffsetFix<6,0,UNSIGNED> &id389in_a = id0out_hsize;
    const HWOffsetFix<6,0,UNSIGNED> &id389in_b = id546out_value;

    id389out_result[(getCycle()+1)%2] = (sub_fixed<6,0,UNSIGNED,TONEAREVEN>(id389in_a,id389in_b));
  }
  { // Node ID: 552 (NodeEqInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id552in_a = id612out_output[getCycle()%2];
    const HWOffsetFix<6,0,UNSIGNED> &id552in_b = id389out_result[getCycle()%2];

    id552out_result[(getCycle()+1)%2] = (eq_fixed(id552in_a,id552in_b));
  }
  { // Node ID: 545 (NodeConstantRawBits)
  }
  { // Node ID: 392 (NodeSub)
    const HWOffsetFix<16,0,UNSIGNED> &id392in_a = id790out_value;
    const HWOffsetFix<16,0,UNSIGNED> &id392in_b = id545out_value;

    id392out_result[(getCycle()+1)%2] = (sub_fixed<16,0,UNSIGNED,TONEAREVEN>(id392in_a,id392in_b));
  }
  { // Node ID: 553 (NodeEqInlined)
    const HWOffsetFix<16,0,UNSIGNED> &id553in_a = id613out_output[getCycle()%2];
    const HWOffsetFix<16,0,UNSIGNED> &id553in_b = id392out_result[getCycle()%2];

    id553out_result[(getCycle()+1)%2] = (eq_fixed(id553in_a,id553in_b));
  }
  { // Node ID: 394 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id394in_a = id552out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id394in_b = id553out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id394x_1;

    (id394x_1) = (and_fixed(id394in_a,id394in_b));
    id394out_result[(getCycle()+1)%2] = (id394x_1);
  }
  { // Node ID: 769 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id769in_input = id394out_result[getCycle()%2];

    id769out_output[(getCycle()+126)%127] = id769in_input;
  }
  { // Node ID: 400 (NodeConstantRawBits)
  }
  { // Node ID: 544 (NodeConstantRawBits)
  }
  { // Node ID: 231 (NodeSub)
    const HWOffsetFix<6,0,UNSIGNED> &id231in_a = id0out_hsize;
    const HWOffsetFix<6,0,UNSIGNED> &id231in_b = id544out_value;

    id231out_result[(getCycle()+1)%2] = (sub_fixed<6,0,UNSIGNED,TONEAREVEN>(id231in_a,id231in_b));
  }
  { // Node ID: 554 (NodeEqInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id554in_a = id612out_output[getCycle()%2];
    const HWOffsetFix<6,0,UNSIGNED> &id554in_b = id231out_result[getCycle()%2];

    id554out_result[(getCycle()+1)%2] = (eq_fixed(id554in_a,id554in_b));
  }
  { // Node ID: 543 (NodeConstantRawBits)
  }
  { // Node ID: 234 (NodeSub)
    const HWOffsetFix<16,0,UNSIGNED> &id234in_a = id790out_value;
    const HWOffsetFix<16,0,UNSIGNED> &id234in_b = id543out_value;

    id234out_result[(getCycle()+1)%2] = (sub_fixed<16,0,UNSIGNED,TONEAREVEN>(id234in_a,id234in_b));
  }
  { // Node ID: 555 (NodeEqInlined)
    const HWOffsetFix<16,0,UNSIGNED> &id555in_a = id613out_output[getCycle()%2];
    const HWOffsetFix<16,0,UNSIGNED> &id555in_b = id234out_result[getCycle()%2];

    id555out_result[(getCycle()+1)%2] = (eq_fixed(id555in_a,id555in_b));
  }
  { // Node ID: 236 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id236in_a = id554out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id236in_b = id555out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id236x_1;

    (id236x_1) = (and_fixed(id236in_a,id236in_b));
    id236out_result[(getCycle()+1)%2] = (id236x_1);
  }
  { // Node ID: 721 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id721in_input = id236out_result[getCycle()%2];

    id721out_output[(getCycle()+106)%107] = id721in_input;
  }
  { // Node ID: 312 (NodeConstantRawBits)
  }
  { // Node ID: 542 (NodeConstantRawBits)
  }
  { // Node ID: 157 (NodeSub)
    const HWOffsetFix<6,0,UNSIGNED> &id157in_a = id0out_hsize;
    const HWOffsetFix<6,0,UNSIGNED> &id157in_b = id542out_value;

    id157out_result[(getCycle()+1)%2] = (sub_fixed<6,0,UNSIGNED,TONEAREVEN>(id157in_a,id157in_b));
  }
  { // Node ID: 556 (NodeEqInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id556in_a = id612out_output[getCycle()%2];
    const HWOffsetFix<6,0,UNSIGNED> &id556in_b = id157out_result[getCycle()%2];

    id556out_result[(getCycle()+1)%2] = (eq_fixed(id556in_a,id556in_b));
  }
  { // Node ID: 541 (NodeConstantRawBits)
  }
  { // Node ID: 160 (NodeSub)
    const HWOffsetFix<16,0,UNSIGNED> &id160in_a = id790out_value;
    const HWOffsetFix<16,0,UNSIGNED> &id160in_b = id541out_value;

    id160out_result[(getCycle()+1)%2] = (sub_fixed<16,0,UNSIGNED,TONEAREVEN>(id160in_a,id160in_b));
  }
  { // Node ID: 557 (NodeEqInlined)
    const HWOffsetFix<16,0,UNSIGNED> &id557in_a = id613out_output[getCycle()%2];
    const HWOffsetFix<16,0,UNSIGNED> &id557in_b = id160out_result[getCycle()%2];

    id557out_result[(getCycle()+1)%2] = (eq_fixed(id557in_a,id557in_b));
  }
  { // Node ID: 162 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id162in_a = id556out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id162in_b = id557out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id162x_1;

    (id162x_1) = (and_fixed(id162in_a,id162in_b));
    id162out_result[(getCycle()+1)%2] = (id162x_1);
  }
  { // Node ID: 674 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id674in_input = id162out_result[getCycle()%2];

    id674out_output[(getCycle()+59)%60] = id674in_input;
  }
  { // Node ID: 228 (NodeConstantRawBits)
  }
  { // Node ID: 771 (NodeFIFO)
    const HWOffsetFix<6,0,UNSIGNED> &id771in_input = id612out_output[getCycle()%2];

    id771out_output[(getCycle()+1)%2] = id771in_input;
  }
  { // Node ID: 772 (NodeFIFO)
    const HWOffsetFix<6,0,UNSIGNED> &id772in_input = id771out_output[getCycle()%2];

    id772out_output[(getCycle()+6)%7] = id772in_input;
  }
  { // Node ID: 773 (NodeFIFO)
    const HWOffsetFix<6,0,UNSIGNED> &id773in_input = id772out_output[getCycle()%7];

    id773out_output[(getCycle()+2)%3] = id773in_input;
  }
  { // Node ID: 774 (NodeFIFO)
    const HWOffsetFix<6,0,UNSIGNED> &id774in_input = id773out_output[getCycle()%3];

    id774out_output[(getCycle()+19)%20] = id774in_input;
  }
  { // Node ID: 540 (NodeConstantRawBits)
  }
  { // Node ID: 558 (NodeLtInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id558in_a = id774out_output[getCycle()%20];
    const HWOffsetFix<6,0,UNSIGNED> &id558in_b = id540out_value;

    id558out_result[(getCycle()+1)%2] = (lt_fixed(id558in_a,id558in_b));
  }
  { // Node ID: 648 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id648in_input = id558out_result[getCycle()%2];

    id648out_output[(getCycle()+12)%13] = id648in_input;
  }
  { // Node ID: 539 (NodeConstantRawBits)
  }
  { // Node ID: 78 (NodeSub)
    const HWOffsetFix<16,0,UNSIGNED> &id78in_a = id790out_value;
    const HWOffsetFix<16,0,UNSIGNED> &id78in_b = id539out_value;

    id78out_result[(getCycle()+1)%2] = (sub_fixed<16,0,UNSIGNED,TONEAREVEN>(id78in_a,id78in_b));
  }
  { // Node ID: 559 (NodeEqInlined)
    const HWOffsetFix<16,0,UNSIGNED> &id559in_a = id613out_output[getCycle()%2];
    const HWOffsetFix<16,0,UNSIGNED> &id559in_b = id78out_result[getCycle()%2];

    id559out_result[(getCycle()+1)%2] = (eq_fixed(id559in_a,id559in_b));
  }
  { // Node ID: 80 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id81out_result;

  { // Node ID: 81 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id81in_a = id80out_io_Ur_force_disabled;

    id81out_result = (not_fixed(id81in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id82out_result;

  { // Node ID: 82 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id82in_a = id559out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id82in_b = id81out_result;

    HWOffsetFix<1,0,UNSIGNED> id82x_1;

    (id82x_1) = (and_fixed(id82in_a,id82in_b));
    id82out_result = (id82x_1);
  }
  { // Node ID: 622 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id622in_input = id82out_result;

    id622out_output[(getCycle()+5)%6] = id622in_input;
  }
  if ( (getFillLevel() >= (8l)))
  { // Node ID: 83 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id83in_enable = id622out_output[getCycle()%6];

    (id83st_read_next_cycle) = ((id83in_enable.getValueAsBool())&(!(((getFlushLevel())>=(8l))&(isFlushingActive()))));
    queueReadRequest(m_Ur, id83st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 560 (NodeGtInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id560in_a = id773out_output[getCycle()%3];
    const HWOffsetFix<6,0,UNSIGNED> &id560in_b = id0out_hsize;

    id560out_result[(getCycle()+1)%2] = (gt_fixed(id560in_a,id560in_b));
  }
  { // Node ID: 538 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 5 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id5in_enable = id7out_wrap;
    const HWOffsetFix<7,0,UNSIGNED> &id5in_max = id538out_value;

    HWOffsetFix<7,0,UNSIGNED> id5x_1;
    HWOffsetFix<1,0,UNSIGNED> id5x_2;
    HWOffsetFix<1,0,UNSIGNED> id5x_3;
    HWOffsetFix<7,0,UNSIGNED> id5x_4t_1e_1;

    id5out_count = (cast_fixed2fixed<6,0,UNSIGNED,TRUNCATE>((id5st_count)));
    (id5x_1) = (add_fixed<7,0,UNSIGNED,TRUNCATE>((id5st_count),(c_hw_fix_7_0_uns_bits_2)));
    (id5x_2) = (gte_fixed((id5x_1),id5in_max));
    (id5x_3) = (and_fixed((id5x_2),id5in_enable));
    id5out_wrap = (id5x_3);
    if((id5in_enable.getValueAsBool())) {
      if(((id5x_3).getValueAsBool())) {
        (id5st_count) = (c_hw_fix_7_0_uns_bits_1);
      }
      else {
        (id5x_4t_1e_1) = (id5x_1);
        (id5st_count) = (id5x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 624 (NodeFIFO)
    const HWOffsetFix<6,0,UNSIGNED> &id624in_input = id5out_count;

    id624out_output[(getCycle()+1)%2] = id624in_input;
  }
  { // Node ID: 537 (NodeConstantRawBits)
  }
  { // Node ID: 561 (NodeEqInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id561in_a = id624out_output[getCycle()%2];
    const HWOffsetFix<6,0,UNSIGNED> &id561in_b = id537out_value;

    id561out_result[(getCycle()+1)%2] = (eq_fixed(id561in_a,id561in_b));
  }
  { // Node ID: 536 (NodeConstantRawBits)
  }
  { // Node ID: 562 (NodeEqInlined)
    const HWOffsetFix<16,0,UNSIGNED> &id562in_a = id613out_output[getCycle()%2];
    const HWOffsetFix<16,0,UNSIGNED> &id562in_b = id536out_value;

    id562out_result[(getCycle()+1)%2] = (eq_fixed(id562in_a,id562in_b));
  }
  { // Node ID: 38 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id38in_a = id561out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id38in_b = id562out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id38x_1;

    (id38x_1) = (and_fixed(id38in_a,id38in_b));
    id38out_result[(getCycle()+1)%2] = (id38x_1);
  }
  { // Node ID: 535 (NodeConstantRawBits)
  }
  { // Node ID: 563 (NodeLtInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id563in_a = id771out_output[getCycle()%2];
    const HWOffsetFix<6,0,UNSIGNED> &id563in_b = id535out_value;

    id563out_result[(getCycle()+1)%2] = (lt_fixed(id563in_a,id563in_b));
  }
  { // Node ID: 41 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id41in_a = id38out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id41in_b = id563out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id41x_1;

    (id41x_1) = (and_fixed(id41in_a,id41in_b));
    id41out_result[(getCycle()+1)%2] = (id41x_1);
  }
  { // Node ID: 631 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id631in_input = id41out_result[getCycle()%2];

    id631out_output[(getCycle()+6)%7] = id631in_input;
  }
  { // Node ID: 534 (NodeConstantRawBits)
  }
  { // Node ID: 564 (NodeEqInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id564in_a = id5out_count;
    const HWOffsetFix<6,0,UNSIGNED> &id564in_b = id534out_value;

    id564out_result[(getCycle()+1)%2] = (eq_fixed(id564in_a,id564in_b));
  }
  { // Node ID: 533 (NodeConstantRawBits)
  }
  { // Node ID: 565 (NodeEqInlined)
    const HWOffsetFix<16,0,UNSIGNED> &id565in_a = id8out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id565in_b = id533out_value;

    id565out_result[(getCycle()+1)%2] = (eq_fixed(id565in_a,id565in_b));
  }
  { // Node ID: 13 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id13in_a = id564out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id13in_b = id565out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id13x_1;

    (id13x_1) = (and_fixed(id13in_a,id13in_b));
    id13out_result[(getCycle()+1)%2] = (id13x_1);
  }
  { // Node ID: 532 (NodeConstantRawBits)
  }
  { // Node ID: 566 (NodeLtInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id566in_a = id612out_output[getCycle()%2];
    const HWOffsetFix<6,0,UNSIGNED> &id566in_b = id532out_value;

    id566out_result[(getCycle()+1)%2] = (lt_fixed(id566in_a,id566in_b));
  }
  { // Node ID: 16 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id16in_a = id13out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id16in_b = id566out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id16x_1;

    (id16x_1) = (and_fixed(id16in_a,id16in_b));
    id16out_result[(getCycle()+1)%2] = (id16x_1);
  }
  { // Node ID: 17 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id18out_result;

  { // Node ID: 18 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id18in_a = id17out_io_ht_force_disabled;

    id18out_result = (not_fixed(id18in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id19out_result;

  { // Node ID: 19 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id19in_a = id16out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id19in_b = id18out_result;

    HWOffsetFix<1,0,UNSIGNED> id19x_1;

    (id19x_1) = (and_fixed(id19in_a,id19in_b));
    id19out_result = (id19x_1);
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 20 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id20in_enable = id19out_result;

    (id20st_read_next_cycle) = ((id20in_enable.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    queueReadRequest(m_ht, id20st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 629 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id629in_input = id16out_result[getCycle()%2];

    id629out_output[(getCycle()+5)%6] = id629in_input;
  }
  if ( (getFillLevel() >= (9l)))
  { // Node ID: 413 (NodeRAM)
    const bool id413_inputvalid = !(isFlushingActive() && getFlushLevel() >= (9l));
    const HWOffsetFix<6,0,UNSIGNED> &id413in_addrA = id772out_output[getCycle()%7];
    const HWFloat<8,24> &id413in_dina = id20out_data;
    const HWOffsetFix<1,0,UNSIGNED> &id413in_wea = id629out_output[getCycle()%6];
    const HWOffsetFix<6,0,UNSIGNED> &id413in_addrB = id772out_output[getCycle()%7];

    long id413x_1;
    long id413x_2;
    HWFloat<8,24> id413x_3;

    (id413x_1) = (id413in_addrA.getValueAsLong());
    (id413x_2) = (id413in_addrB.getValueAsLong());
    switch(((long)((id413x_2)<(53l)))) {
      case 0l:
        id413x_3 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
      case 1l:
        id413x_3 = (id413sta_ram_store[(id413x_2)]);
        break;
      default:
        id413x_3 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id413out_doutb[(getCycle()+2)%3] = (id413x_3);
    if(((id413in_wea.getValueAsBool())&id413_inputvalid)) {
      if(((id413x_1)<(53l))) {
        (id413sta_ram_store[(id413x_1)]) = id413in_dina;
      }
      else {
        throw std::runtime_error((format_string_GRURnnKernel_1("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 413) on port A, ram depth is 53.")));
      }
    }
  }
  { // Node ID: 632 (NodeFIFO)
    const HWFloat<8,24> &id632in_input = id20out_data;

    id632out_output[(getCycle()+2)%3] = id632in_input;
  }
  { // Node ID: 42 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id42in_sel = id631out_output[getCycle()%7];
    const HWFloat<8,24> &id42in_option0 = id413out_doutb[getCycle()%3];
    const HWFloat<8,24> &id42in_option1 = id632out_output[getCycle()%3];

    HWFloat<8,24> id42x_1;

    switch((id42in_sel.getValueAsLong())) {
      case 0l:
        id42x_1 = id42in_option0;
        break;
      case 1l:
        id42x_1 = id42in_option1;
        break;
      default:
        id42x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id42out_result[(getCycle()+1)%2] = (id42x_1);
  }
  { // Node ID: 44 (NodeConstantRawBits)
  }
  { // Node ID: 45 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id45in_sel = id560out_result[getCycle()%2];
    const HWFloat<8,24> &id45in_option0 = id42out_result[getCycle()%2];
    const HWFloat<8,24> &id45in_option1 = id44out_value;

    HWFloat<8,24> id45x_1;

    switch((id45in_sel.getValueAsLong())) {
      case 0l:
        id45x_1 = id45in_option0;
        break;
      case 1l:
        id45x_1 = id45in_option1;
        break;
      default:
        id45x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id45out_result[(getCycle()+1)%2] = (id45x_1);
  }
  { // Node ID: 134 (NodeMul)
    const HWFloat<8,24> &id134in_a = id83out_data;
    const HWFloat<8,24> &id134in_b = id45out_result[getCycle()%2];

    id134out_result[(getCycle()+8)%9] = (mul_float(id134in_a,id134in_b));
  }
  { // Node ID: 634 (NodeFIFO)
    const HWFloat<8,24> &id634in_input = id134out_result[getCycle()%9];

    id634out_output[(getCycle()+11)%12] = id634in_input;
  }
  { // Node ID: 531 (NodeConstantRawBits)
  }
  { // Node ID: 567 (NodeEqInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id567in_a = id774out_output[getCycle()%20];
    const HWOffsetFix<6,0,UNSIGNED> &id567in_b = id531out_value;

    id567out_result[(getCycle()+1)%2] = (eq_fixed(id567in_a,id567in_b));
  }
  HWFloat<8,24> id608out_output;

  { // Node ID: 608 (NodeStreamOffset)
    const HWFloat<8,24> &id608in_input = id136out_result[getCycle()%2];

    id608out_output = id608in_input;
  }
  { // Node ID: 126 (NodeConstantRawBits)
  }
  { // Node ID: 127 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id127in_sel = id567out_result[getCycle()%2];
    const HWFloat<8,24> &id127in_option0 = id608out_output;
    const HWFloat<8,24> &id127in_option1 = id126out_value;

    HWFloat<8,24> id127x_1;

    switch((id127in_sel.getValueAsLong())) {
      case 0l:
        id127x_1 = id127in_option0;
        break;
      case 1l:
        id127x_1 = id127in_option1;
        break;
      default:
        id127x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id127out_result[(getCycle()+1)%2] = (id127x_1);
  }
  { // Node ID: 135 (NodeAdd)
    const HWFloat<8,24> &id135in_a = id634out_output[getCycle()%12];
    const HWFloat<8,24> &id135in_b = id127out_result[getCycle()%2];

    id135out_result[(getCycle()+11)%12] = (add_float(id135in_a,id135in_b));
  }
  { // Node ID: 530 (NodeConstantRawBits)
  }
  { // Node ID: 85 (NodeSub)
    const HWOffsetFix<16,0,UNSIGNED> &id85in_a = id790out_value;
    const HWOffsetFix<16,0,UNSIGNED> &id85in_b = id530out_value;

    id85out_result[(getCycle()+1)%2] = (sub_fixed<16,0,UNSIGNED,TONEAREVEN>(id85in_a,id85in_b));
  }
  { // Node ID: 568 (NodeEqInlined)
    const HWOffsetFix<16,0,UNSIGNED> &id568in_a = id613out_output[getCycle()%2];
    const HWOffsetFix<16,0,UNSIGNED> &id568in_b = id85out_result[getCycle()%2];

    id568out_result[(getCycle()+1)%2] = (eq_fixed(id568in_a,id568in_b));
  }
  { // Node ID: 529 (NodeConstantRawBits)
  }
  { // Node ID: 569 (NodeLtInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id569in_a = id612out_output[getCycle()%2];
    const HWOffsetFix<6,0,UNSIGNED> &id569in_b = id529out_value;

    id569out_result[(getCycle()+1)%2] = (lt_fixed(id569in_a,id569in_b));
  }
  { // Node ID: 89 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id89in_a = id568out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id89in_b = id569out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id89x_1;

    (id89x_1) = (and_fixed(id89in_a,id89in_b));
    id89out_result[(getCycle()+1)%2] = (id89x_1);
  }
  { // Node ID: 90 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id91out_result;

  { // Node ID: 91 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id91in_a = id90out_io_Wr_force_disabled;

    id91out_result = (not_fixed(id91in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id92out_result;

  { // Node ID: 92 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id92in_a = id89out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id92in_b = id91out_result;

    HWOffsetFix<1,0,UNSIGNED> id92x_1;

    (id92x_1) = (and_fixed(id92in_a,id92in_b));
    id92out_result = (id92x_1);
  }
  { // Node ID: 637 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id637in_input = id92out_result;

    id637out_output[(getCycle()+4)%5] = id637in_input;
  }
  if ( (getFillLevel() >= (8l)))
  { // Node ID: 93 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id93in_enable = id637out_output[getCycle()%5];

    (id93st_read_next_cycle) = ((id93in_enable.getValueAsBool())&(!(((getFlushLevel())>=(8l))&(isFlushingActive()))));
    queueReadRequest(m_Wr, id93st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 528 (NodeConstantRawBits)
  }
  { // Node ID: 570 (NodeGtInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id570in_a = id773out_output[getCycle()%3];
    const HWOffsetFix<6,0,UNSIGNED> &id570in_b = id528out_value;

    id570out_result[(getCycle()+1)%2] = (gt_fixed(id570in_a,id570in_b));
  }
  { // Node ID: 527 (NodeConstantRawBits)
  }
  { // Node ID: 571 (NodeEqInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id571in_a = id624out_output[getCycle()%2];
    const HWOffsetFix<6,0,UNSIGNED> &id571in_b = id527out_value;

    id571out_result[(getCycle()+1)%2] = (eq_fixed(id571in_a,id571in_b));
  }
  { // Node ID: 526 (NodeConstantRawBits)
  }
  { // Node ID: 572 (NodeEqInlined)
    const HWOffsetFix<16,0,UNSIGNED> &id572in_a = id613out_output[getCycle()%2];
    const HWOffsetFix<16,0,UNSIGNED> &id572in_b = id526out_value;

    id572out_result[(getCycle()+1)%2] = (eq_fixed(id572in_a,id572in_b));
  }
  { // Node ID: 50 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id50in_a = id571out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id50in_b = id572out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id50x_1;

    (id50x_1) = (and_fixed(id50in_a,id50in_b));
    id50out_result[(getCycle()+1)%2] = (id50x_1);
  }
  { // Node ID: 525 (NodeConstantRawBits)
  }
  { // Node ID: 573 (NodeLtInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id573in_a = id771out_output[getCycle()%2];
    const HWOffsetFix<6,0,UNSIGNED> &id573in_b = id525out_value;

    id573out_result[(getCycle()+1)%2] = (lt_fixed(id573in_a,id573in_b));
  }
  { // Node ID: 53 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id53in_a = id50out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id53in_b = id573out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id53x_1;

    (id53x_1) = (and_fixed(id53in_a,id53in_b));
    id53out_result[(getCycle()+1)%2] = (id53x_1);
  }
  { // Node ID: 646 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id646in_input = id53out_result[getCycle()%2];

    id646out_output[(getCycle()+6)%7] = id646in_input;
  }
  HWOffsetFix<5,0,UNSIGNED> id33out_o;

  { // Node ID: 33 (NodeCast)
    const HWOffsetFix<6,0,UNSIGNED> &id33in_i = id772out_output[getCycle()%7];

    id33out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id33in_i));
  }
  { // Node ID: 524 (NodeConstantRawBits)
  }
  { // Node ID: 574 (NodeEqInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id574in_a = id5out_count;
    const HWOffsetFix<6,0,UNSIGNED> &id574in_b = id524out_value;

    id574out_result[(getCycle()+1)%2] = (eq_fixed(id574in_a,id574in_b));
  }
  { // Node ID: 523 (NodeConstantRawBits)
  }
  { // Node ID: 575 (NodeEqInlined)
    const HWOffsetFix<16,0,UNSIGNED> &id575in_a = id8out_count;
    const HWOffsetFix<16,0,UNSIGNED> &id575in_b = id523out_value;

    id575out_result[(getCycle()+1)%2] = (eq_fixed(id575in_a,id575in_b));
  }
  { // Node ID: 25 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id25in_a = id574out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id25in_b = id575out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id25x_1;

    (id25x_1) = (and_fixed(id25in_a,id25in_b));
    id25out_result[(getCycle()+1)%2] = (id25x_1);
  }
  { // Node ID: 522 (NodeConstantRawBits)
  }
  { // Node ID: 576 (NodeLtInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id576in_a = id612out_output[getCycle()%2];
    const HWOffsetFix<6,0,UNSIGNED> &id576in_b = id522out_value;

    id576out_result[(getCycle()+1)%2] = (lt_fixed(id576in_a,id576in_b));
  }
  { // Node ID: 28 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id28in_a = id25out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id28in_b = id576out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id28x_1;

    (id28x_1) = (and_fixed(id28in_a,id28in_b));
    id28out_result[(getCycle()+1)%2] = (id28x_1);
  }
  { // Node ID: 29 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id30out_result;

  { // Node ID: 30 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id30in_a = id29out_io_xt_force_disabled;

    id30out_result = (not_fixed(id30in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id31out_result;

  { // Node ID: 31 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id31in_a = id28out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id31in_b = id30out_result;

    HWOffsetFix<1,0,UNSIGNED> id31x_1;

    (id31x_1) = (and_fixed(id31in_a,id31in_b));
    id31out_result = (id31x_1);
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 32 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id32in_enable = id31out_result;

    (id32st_read_next_cycle) = ((id32in_enable.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    queueReadRequest(m_xt, id32st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 645 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id645in_input = id28out_result[getCycle()%2];

    id645out_output[(getCycle()+5)%6] = id645in_input;
  }
  HWOffsetFix<5,0,UNSIGNED> id54out_o;

  { // Node ID: 54 (NodeCast)
    const HWOffsetFix<6,0,UNSIGNED> &id54in_i = id772out_output[getCycle()%7];

    id54out_o = (cast_fixed2fixed<5,0,UNSIGNED,TONEAREVEN>(id54in_i));
  }
  if ( (getFillLevel() >= (9l)))
  { // Node ID: 415 (NodeRAM)
    const bool id415_inputvalid = !(isFlushingActive() && getFlushLevel() >= (9l));
    const HWOffsetFix<5,0,UNSIGNED> &id415in_addrA = id33out_o;
    const HWFloat<8,24> &id415in_dina = id32out_data;
    const HWOffsetFix<1,0,UNSIGNED> &id415in_wea = id645out_output[getCycle()%6];
    const HWOffsetFix<5,0,UNSIGNED> &id415in_addrB = id54out_o;

    long id415x_1;
    long id415x_2;
    HWFloat<8,24> id415x_3;

    (id415x_1) = (id415in_addrA.getValueAsLong());
    (id415x_2) = (id415in_addrB.getValueAsLong());
    switch(((long)((id415x_2)<(21l)))) {
      case 0l:
        id415x_3 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
      case 1l:
        id415x_3 = (id415sta_ram_store[(id415x_2)]);
        break;
      default:
        id415x_3 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id415out_doutb[(getCycle()+2)%3] = (id415x_3);
    if(((id415in_wea.getValueAsBool())&id415_inputvalid)) {
      if(((id415x_1)<(21l))) {
        (id415sta_ram_store[(id415x_1)]) = id415in_dina;
      }
      else {
        throw std::runtime_error((format_string_GRURnnKernel_2("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 415) on port A, ram depth is 21.")));
      }
    }
  }
  { // Node ID: 647 (NodeFIFO)
    const HWFloat<8,24> &id647in_input = id32out_data;

    id647out_output[(getCycle()+2)%3] = id647in_input;
  }
  { // Node ID: 55 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id55in_sel = id646out_output[getCycle()%7];
    const HWFloat<8,24> &id55in_option0 = id415out_doutb[getCycle()%3];
    const HWFloat<8,24> &id55in_option1 = id647out_output[getCycle()%3];

    HWFloat<8,24> id55x_1;

    switch((id55in_sel.getValueAsLong())) {
      case 0l:
        id55x_1 = id55in_option0;
        break;
      case 1l:
        id55x_1 = id55in_option1;
        break;
      default:
        id55x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id55out_result[(getCycle()+1)%2] = (id55x_1);
  }
  { // Node ID: 58 (NodeConstantRawBits)
  }
  { // Node ID: 59 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id59in_sel = id570out_result[getCycle()%2];
    const HWFloat<8,24> &id59in_option0 = id55out_result[getCycle()%2];
    const HWFloat<8,24> &id59in_option1 = id58out_value;

    HWFloat<8,24> id59x_1;

    switch((id59in_sel.getValueAsLong())) {
      case 0l:
        id59x_1 = id59in_option0;
        break;
      case 1l:
        id59x_1 = id59in_option1;
        break;
      default:
        id59x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id59out_result[(getCycle()+1)%2] = (id59x_1);
  }
  { // Node ID: 131 (NodeMul)
    const HWFloat<8,24> &id131in_a = id93out_data;
    const HWFloat<8,24> &id131in_b = id59out_result[getCycle()%2];

    id131out_result[(getCycle()+8)%9] = (mul_float(id131in_a,id131in_b));
  }
  { // Node ID: 132 (NodeAdd)
    const HWFloat<8,24> &id132in_a = id134out_result[getCycle()%9];
    const HWFloat<8,24> &id132in_b = id131out_result[getCycle()%9];

    id132out_result[(getCycle()+11)%12] = (add_float(id132in_a,id132in_b));
  }
  { // Node ID: 133 (NodeAdd)
    const HWFloat<8,24> &id133in_a = id132out_result[getCycle()%12];
    const HWFloat<8,24> &id133in_b = id127out_result[getCycle()%2];

    id133out_result[(getCycle()+11)%12] = (add_float(id133in_a,id133in_b));
  }
  { // Node ID: 136 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id136in_sel = id648out_output[getCycle()%13];
    const HWFloat<8,24> &id136in_option0 = id135out_result[getCycle()%12];
    const HWFloat<8,24> &id136in_option1 = id133out_result[getCycle()%12];

    HWFloat<8,24> id136x_1;

    switch((id136in_sel.getValueAsLong())) {
      case 0l:
        id136x_1 = id136in_option0;
        break;
      case 1l:
        id136x_1 = id136in_option1;
        break;
      default:
        id136x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id136out_result[(getCycle()+1)%2] = (id136x_1);
  }
  { // Node ID: 663 (NodeFIFO)
    const HWFloat<8,24> &id663in_input = id136out_result[getCycle()%2];

    id663out_output[(getCycle()+1)%2] = id663in_input;
  }
  { // Node ID: 777 (NodeFIFO)
    const HWFloat<8,24> &id777in_input = id663out_output[getCycle()%2];

    id777out_output[(getCycle()+1)%2] = id777in_input;
  }
  { // Node ID: 778 (NodeFIFO)
    const HWFloat<8,24> &id778in_input = id777out_output[getCycle()%2];

    id778out_output[(getCycle()+1)%2] = id778in_input;
  }
  { // Node ID: 779 (NodeFIFO)
    const HWFloat<8,24> &id779in_input = id778out_output[getCycle()%2];

    id779out_output[(getCycle()+1)%2] = id779in_input;
  }
  { // Node ID: 780 (NodeFIFO)
    const HWFloat<8,24> &id780in_input = id779out_output[getCycle()%2];

    id780out_output[(getCycle()+1)%2] = id780in_input;
  }
  { // Node ID: 521 (NodeConstantRawBits)
  }
  { // Node ID: 164 (NodeLt)
    const HWFloat<8,24> &id164in_a = id780out_output[getCycle()%2];
    const HWFloat<8,24> &id164in_b = id521out_value;

    id164out_result[(getCycle()+2)%3] = (lt_float(id164in_a,id164in_b));
  }
  { // Node ID: 673 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id673in_input = id164out_result[getCycle()%3];

    id673out_output[(getCycle()+11)%12] = id673in_input;
  }
  { // Node ID: 520 (NodeConstantRawBits)
  }
  { // Node ID: 166 (NodeGte)
    const HWFloat<8,24> &id166in_a = id780out_output[getCycle()%2];
    const HWFloat<8,24> &id166in_b = id520out_value;

    id166out_result[(getCycle()+2)%3] = (gte_float(id166in_a,id166in_b));
  }
  { // Node ID: 519 (NodeConstantRawBits)
  }
  { // Node ID: 168 (NodeLt)
    const HWFloat<8,24> &id168in_a = id780out_output[getCycle()%2];
    const HWFloat<8,24> &id168in_b = id519out_value;

    id168out_result[(getCycle()+2)%3] = (lt_float(id168in_a,id168in_b));
  }
  { // Node ID: 169 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id169in_a = id166out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id169in_b = id168out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id169x_1;

    (id169x_1) = (and_fixed(id169in_a,id169in_b));
    id169out_result[(getCycle()+1)%2] = (id169x_1);
  }
  { // Node ID: 672 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id672in_input = id169out_result[getCycle()%2];

    id672out_output[(getCycle()+9)%10] = id672in_input;
  }
  { // Node ID: 518 (NodeConstantRawBits)
  }
  { // Node ID: 175 (NodeGte)
    const HWFloat<8,24> &id175in_a = id780out_output[getCycle()%2];
    const HWFloat<8,24> &id175in_b = id518out_value;

    id175out_result[(getCycle()+2)%3] = (gte_float(id175in_a,id175in_b));
  }
  { // Node ID: 517 (NodeConstantRawBits)
  }
  { // Node ID: 177 (NodeLt)
    const HWFloat<8,24> &id177in_a = id780out_output[getCycle()%2];
    const HWFloat<8,24> &id177in_b = id517out_value;

    id177out_result[(getCycle()+2)%3] = (lt_float(id177in_a,id177in_b));
  }
  { // Node ID: 178 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id178in_a = id175out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id178in_b = id177out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id178x_1;

    (id178x_1) = (and_fixed(id178in_a,id178in_b));
    id178out_result[(getCycle()+1)%2] = (id178x_1);
  }
  { // Node ID: 670 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id670in_input = id178out_result[getCycle()%2];

    id670out_output[(getCycle()+8)%9] = id670in_input;
  }
  { // Node ID: 516 (NodeConstantRawBits)
  }
  { // Node ID: 184 (NodeGte)
    const HWFloat<8,24> &id184in_a = id780out_output[getCycle()%2];
    const HWFloat<8,24> &id184in_b = id516out_value;

    id184out_result[(getCycle()+2)%3] = (gte_float(id184in_a,id184in_b));
  }
  { // Node ID: 515 (NodeConstantRawBits)
  }
  { // Node ID: 186 (NodeLt)
    const HWFloat<8,24> &id186in_a = id780out_output[getCycle()%2];
    const HWFloat<8,24> &id186in_b = id515out_value;

    id186out_result[(getCycle()+2)%3] = (lt_float(id186in_a,id186in_b));
  }
  { // Node ID: 187 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id187in_a = id184out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id187in_b = id186out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id187x_1;

    (id187x_1) = (and_fixed(id187in_a,id187in_b));
    id187out_result[(getCycle()+1)%2] = (id187x_1);
  }
  { // Node ID: 668 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id668in_input = id187out_result[getCycle()%2];

    id668out_output[(getCycle()+7)%8] = id668in_input;
  }
  { // Node ID: 514 (NodeConstantRawBits)
  }
  { // Node ID: 193 (NodeGte)
    const HWFloat<8,24> &id193in_a = id780out_output[getCycle()%2];
    const HWFloat<8,24> &id193in_b = id514out_value;

    id193out_result[(getCycle()+2)%3] = (gte_float(id193in_a,id193in_b));
  }
  { // Node ID: 513 (NodeConstantRawBits)
  }
  { // Node ID: 195 (NodeLt)
    const HWFloat<8,24> &id195in_a = id780out_output[getCycle()%2];
    const HWFloat<8,24> &id195in_b = id513out_value;

    id195out_result[(getCycle()+2)%3] = (lt_float(id195in_a,id195in_b));
  }
  { // Node ID: 196 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id196in_a = id193out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id196in_b = id195out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id196x_1;

    (id196x_1) = (and_fixed(id196in_a,id196in_b));
    id196out_result[(getCycle()+1)%2] = (id196x_1);
  }
  { // Node ID: 666 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id666in_input = id196out_result[getCycle()%2];

    id666out_output[(getCycle()+6)%7] = id666in_input;
  }
  { // Node ID: 512 (NodeConstantRawBits)
  }
  { // Node ID: 202 (NodeGte)
    const HWFloat<8,24> &id202in_a = id780out_output[getCycle()%2];
    const HWFloat<8,24> &id202in_b = id512out_value;

    id202out_result[(getCycle()+2)%3] = (gte_float(id202in_a,id202in_b));
  }
  { // Node ID: 511 (NodeConstantRawBits)
  }
  { // Node ID: 204 (NodeLt)
    const HWFloat<8,24> &id204in_a = id780out_output[getCycle()%2];
    const HWFloat<8,24> &id204in_b = id511out_value;

    id204out_result[(getCycle()+2)%3] = (lt_float(id204in_a,id204in_b));
  }
  { // Node ID: 205 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id205in_a = id202out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id205in_b = id204out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id205x_1;

    (id205x_1) = (and_fixed(id205in_a,id205in_b));
    id205out_result[(getCycle()+1)%2] = (id205x_1);
  }
  { // Node ID: 664 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id664in_input = id205out_result[getCycle()%2];

    id664out_output[(getCycle()+5)%6] = id664in_input;
  }
  { // Node ID: 510 (NodeConstantRawBits)
  }
  { // Node ID: 211 (NodeGte)
    const HWFloat<8,24> &id211in_a = id780out_output[getCycle()%2];
    const HWFloat<8,24> &id211in_b = id510out_value;

    id211out_result[(getCycle()+2)%3] = (gte_float(id211in_a,id211in_b));
  }
  { // Node ID: 509 (NodeConstantRawBits)
  }
  { // Node ID: 213 (NodeLt)
    const HWFloat<8,24> &id213in_a = id780out_output[getCycle()%2];
    const HWFloat<8,24> &id213in_b = id509out_value;

    id213out_result[(getCycle()+2)%3] = (lt_float(id213in_a,id213in_b));
  }
  { // Node ID: 214 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id214in_a = id211out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id214in_b = id213out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id214x_1;

    (id214x_1) = (and_fixed(id214in_a,id214in_b));
    id214out_result[(getCycle()+1)%2] = (id214x_1);
  }
  { // Node ID: 662 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id662in_input = id214out_result[getCycle()%2];

    id662out_output[(getCycle()+4)%5] = id662in_input;
  }
  { // Node ID: 219 (NodeConstantRawBits)
  }
  { // Node ID: 591 (NodePO2FPMult)
    const HWFloat<8,24> &id591in_floatIn = id136out_result[getCycle()%2];

    id591out_floatOut[(getCycle()+1)%2] = (mul_float(id591in_floatIn,(c_hw_flt_8_24_0_03125val)));
  }
  { // Node ID: 507 (NodeConstantRawBits)
  }
  { // Node ID: 218 (NodeAdd)
    const HWFloat<8,24> &id218in_a = id591out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id218in_b = id507out_value;

    id218out_result[(getCycle()+11)%12] = (add_float(id218in_a,id218in_b));
  }
  { // Node ID: 220 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id220in_sel = id662out_output[getCycle()%5];
    const HWFloat<8,24> &id220in_option0 = id219out_value;
    const HWFloat<8,24> &id220in_option1 = id218out_result[getCycle()%12];

    HWFloat<8,24> id220x_1;

    switch((id220in_sel.getValueAsLong())) {
      case 0l:
        id220x_1 = id220in_option0;
        break;
      case 1l:
        id220x_1 = id220in_option1;
        break;
      default:
        id220x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id220out_result[(getCycle()+1)%2] = (id220x_1);
  }
  { // Node ID: 592 (NodePO2FPMult)
    const HWFloat<8,24> &id592in_floatIn = id663out_output[getCycle()%2];

    id592out_floatOut[(getCycle()+1)%2] = (mul_float(id592in_floatIn,(c_hw_flt_8_24_0_125val)));
  }
  { // Node ID: 505 (NodeConstantRawBits)
  }
  { // Node ID: 209 (NodeAdd)
    const HWFloat<8,24> &id209in_a = id592out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id209in_b = id505out_value;

    id209out_result[(getCycle()+11)%12] = (add_float(id209in_a,id209in_b));
  }
  { // Node ID: 221 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id221in_sel = id664out_output[getCycle()%6];
    const HWFloat<8,24> &id221in_option0 = id220out_result[getCycle()%2];
    const HWFloat<8,24> &id221in_option1 = id209out_result[getCycle()%12];

    HWFloat<8,24> id221x_1;

    switch((id221in_sel.getValueAsLong())) {
      case 0l:
        id221x_1 = id221in_option0;
        break;
      case 1l:
        id221x_1 = id221in_option1;
        break;
      default:
        id221x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id221out_result[(getCycle()+1)%2] = (id221x_1);
  }
  { // Node ID: 593 (NodePO2FPMult)
    const HWFloat<8,24> &id593in_floatIn = id777out_output[getCycle()%2];

    id593out_floatOut[(getCycle()+1)%2] = (mul_float(id593in_floatIn,(c_hw_flt_8_24_0_25val)));
  }
  { // Node ID: 503 (NodeConstantRawBits)
  }
  { // Node ID: 200 (NodeAdd)
    const HWFloat<8,24> &id200in_a = id593out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id200in_b = id503out_value;

    id200out_result[(getCycle()+11)%12] = (add_float(id200in_a,id200in_b));
  }
  { // Node ID: 222 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id222in_sel = id666out_output[getCycle()%7];
    const HWFloat<8,24> &id222in_option0 = id221out_result[getCycle()%2];
    const HWFloat<8,24> &id222in_option1 = id200out_result[getCycle()%12];

    HWFloat<8,24> id222x_1;

    switch((id222in_sel.getValueAsLong())) {
      case 0l:
        id222x_1 = id222in_option0;
        break;
      case 1l:
        id222x_1 = id222in_option1;
        break;
      default:
        id222x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id222out_result[(getCycle()+1)%2] = (id222x_1);
  }
  { // Node ID: 594 (NodePO2FPMult)
    const HWFloat<8,24> &id594in_floatIn = id778out_output[getCycle()%2];

    id594out_floatOut[(getCycle()+1)%2] = (mul_float(id594in_floatIn,(c_hw_flt_8_24_0_25val)));
  }
  { // Node ID: 501 (NodeConstantRawBits)
  }
  { // Node ID: 191 (NodeAdd)
    const HWFloat<8,24> &id191in_a = id594out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id191in_b = id501out_value;

    id191out_result[(getCycle()+11)%12] = (add_float(id191in_a,id191in_b));
  }
  { // Node ID: 223 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id223in_sel = id668out_output[getCycle()%8];
    const HWFloat<8,24> &id223in_option0 = id222out_result[getCycle()%2];
    const HWFloat<8,24> &id223in_option1 = id191out_result[getCycle()%12];

    HWFloat<8,24> id223x_1;

    switch((id223in_sel.getValueAsLong())) {
      case 0l:
        id223x_1 = id223in_option0;
        break;
      case 1l:
        id223x_1 = id223in_option1;
        break;
      default:
        id223x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id223out_result[(getCycle()+1)%2] = (id223x_1);
  }
  { // Node ID: 595 (NodePO2FPMult)
    const HWFloat<8,24> &id595in_floatIn = id779out_output[getCycle()%2];

    id595out_floatOut[(getCycle()+1)%2] = (mul_float(id595in_floatIn,(c_hw_flt_8_24_0_125val)));
  }
  { // Node ID: 499 (NodeConstantRawBits)
  }
  { // Node ID: 182 (NodeAdd)
    const HWFloat<8,24> &id182in_a = id595out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id182in_b = id499out_value;

    id182out_result[(getCycle()+11)%12] = (add_float(id182in_a,id182in_b));
  }
  { // Node ID: 224 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id224in_sel = id670out_output[getCycle()%9];
    const HWFloat<8,24> &id224in_option0 = id223out_result[getCycle()%2];
    const HWFloat<8,24> &id224in_option1 = id182out_result[getCycle()%12];

    HWFloat<8,24> id224x_1;

    switch((id224in_sel.getValueAsLong())) {
      case 0l:
        id224x_1 = id224in_option0;
        break;
      case 1l:
        id224x_1 = id224in_option1;
        break;
      default:
        id224x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id224out_result[(getCycle()+1)%2] = (id224x_1);
  }
  { // Node ID: 596 (NodePO2FPMult)
    const HWFloat<8,24> &id596in_floatIn = id780out_output[getCycle()%2];

    id596out_floatOut[(getCycle()+1)%2] = (mul_float(id596in_floatIn,(c_hw_flt_8_24_0_03125val)));
  }
  { // Node ID: 497 (NodeConstantRawBits)
  }
  { // Node ID: 173 (NodeAdd)
    const HWFloat<8,24> &id173in_a = id596out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id173in_b = id497out_value;

    id173out_result[(getCycle()+11)%12] = (add_float(id173in_a,id173in_b));
  }
  { // Node ID: 225 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id225in_sel = id672out_output[getCycle()%10];
    const HWFloat<8,24> &id225in_option0 = id224out_result[getCycle()%2];
    const HWFloat<8,24> &id225in_option1 = id173out_result[getCycle()%12];

    HWFloat<8,24> id225x_1;

    switch((id225in_sel.getValueAsLong())) {
      case 0l:
        id225x_1 = id225in_option0;
        break;
      case 1l:
        id225x_1 = id225in_option1;
        break;
      default:
        id225x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id225out_result[(getCycle()+1)%2] = (id225x_1);
  }
  { // Node ID: 226 (NodeConstantRawBits)
  }
  { // Node ID: 227 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id227in_sel = id673out_output[getCycle()%12];
    const HWFloat<8,24> &id227in_option0 = id225out_result[getCycle()%2];
    const HWFloat<8,24> &id227in_option1 = id226out_value;

    HWFloat<8,24> id227x_1;

    switch((id227in_sel.getValueAsLong())) {
      case 0l:
        id227x_1 = id227in_option0;
        break;
      case 1l:
        id227x_1 = id227in_option1;
        break;
      default:
        id227x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id227out_result[(getCycle()+1)%2] = (id227x_1);
  }
  { // Node ID: 229 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id229in_sel = id674out_output[getCycle()%60];
    const HWFloat<8,24> &id229in_option0 = id228out_value;
    const HWFloat<8,24> &id229in_option1 = id227out_result[getCycle()%2];

    HWFloat<8,24> id229x_1;

    switch((id229in_sel.getValueAsLong())) {
      case 0l:
        id229x_1 = id229in_option0;
        break;
      case 1l:
        id229x_1 = id229in_option1;
        break;
      default:
        id229x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id229out_result[(getCycle()+1)%2] = (id229x_1);
  }
  { // Node ID: 496 (NodeConstantRawBits)
  }
  { // Node ID: 95 (NodeSub)
    const HWOffsetFix<16,0,UNSIGNED> &id95in_a = id790out_value;
    const HWOffsetFix<16,0,UNSIGNED> &id95in_b = id496out_value;

    id95out_result[(getCycle()+1)%2] = (sub_fixed<16,0,UNSIGNED,TONEAREVEN>(id95in_a,id95in_b));
  }
  { // Node ID: 577 (NodeEqInlined)
    const HWOffsetFix<16,0,UNSIGNED> &id577in_a = id613out_output[getCycle()%2];
    const HWOffsetFix<16,0,UNSIGNED> &id577in_b = id95out_result[getCycle()%2];

    id577out_result[(getCycle()+1)%2] = (eq_fixed(id577in_a,id577in_b));
  }
  { // Node ID: 97 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id98out_result;

  { // Node ID: 98 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id98in_a = id97out_io_Uh_force_disabled;

    id98out_result = (not_fixed(id98in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id99out_result;

  { // Node ID: 99 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id99in_a = id577out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id99in_b = id98out_result;

    HWOffsetFix<1,0,UNSIGNED> id99x_1;

    (id99x_1) = (and_fixed(id99in_a,id99in_b));
    id99out_result = (id99x_1);
  }
  { // Node ID: 676 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id676in_input = id99out_result;

    id676out_output[(getCycle()+36)%37] = id676in_input;
  }
  if ( (getFillLevel() >= (39l)))
  { // Node ID: 100 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id100in_enable = id676out_output[getCycle()%37];

    (id100st_read_next_cycle) = ((id100in_enable.getValueAsBool())&(!(((getFlushLevel())>=(39l))&(isFlushingActive()))));
    queueReadRequest(m_Uh, id100st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 677 (NodeFIFO)
    const HWFloat<8,24> &id677in_input = id45out_result[getCycle()%2];

    id677out_output[(getCycle()+31)%32] = id677in_input;
  }
  { // Node ID: 145 (NodeMul)
    const HWFloat<8,24> &id145in_a = id100out_data;
    const HWFloat<8,24> &id145in_b = id677out_output[getCycle()%32];

    id145out_result[(getCycle()+8)%9] = (mul_float(id145in_a,id145in_b));
  }
  { // Node ID: 495 (NodeConstantRawBits)
  }
  { // Node ID: 578 (NodeEqInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id578in_a = id774out_output[getCycle()%20];
    const HWOffsetFix<6,0,UNSIGNED> &id578in_b = id495out_value;

    id578out_result[(getCycle()+1)%2] = (eq_fixed(id578in_a,id578in_b));
  }
  { // Node ID: 680 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id680in_input = id578out_result[getCycle()%2];

    id680out_output[(getCycle()+20)%21] = id680in_input;
  }
  HWFloat<8,24> id609out_output;

  { // Node ID: 609 (NodeStreamOffset)
    const HWFloat<8,24> &id609in_input = id679out_output[getCycle()%2];

    id609out_output = id609in_input;
  }
  { // Node ID: 139 (NodeConstantRawBits)
  }
  { // Node ID: 140 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id140in_sel = id680out_output[getCycle()%21];
    const HWFloat<8,24> &id140in_option0 = id609out_output;
    const HWFloat<8,24> &id140in_option1 = id139out_value;

    HWFloat<8,24> id140x_1;

    switch((id140in_sel.getValueAsLong())) {
      case 0l:
        id140x_1 = id140in_option0;
        break;
      case 1l:
        id140x_1 = id140in_option1;
        break;
      default:
        id140x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id140out_result[(getCycle()+1)%2] = (id140x_1);
  }
  { // Node ID: 146 (NodeAdd)
    const HWFloat<8,24> &id146in_a = id145out_result[getCycle()%9];
    const HWFloat<8,24> &id146in_b = id140out_result[getCycle()%2];

    id146out_result[(getCycle()+11)%12] = (add_float(id146in_a,id146in_b));
  }
  { // Node ID: 679 (NodeFIFO)
    const HWFloat<8,24> &id679in_input = id146out_result[getCycle()%12];

    id679out_output[(getCycle()+1)%2] = id679in_input;
  }
  { // Node ID: 237 (NodeMul)
    const HWFloat<8,24> &id237in_a = id229out_result[getCycle()%2];
    const HWFloat<8,24> &id237in_b = id679out_output[getCycle()%2];

    id237out_result[(getCycle()+8)%9] = (mul_float(id237in_a,id237in_b));
  }
  { // Node ID: 494 (NodeConstantRawBits)
  }
  { // Node ID: 579 (NodeLtInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id579in_a = id774out_output[getCycle()%20];
    const HWOffsetFix<6,0,UNSIGNED> &id579in_b = id494out_value;

    id579out_result[(getCycle()+1)%2] = (lt_fixed(id579in_a,id579in_b));
  }
  { // Node ID: 689 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id689in_input = id579out_result[getCycle()%2];

    id689out_output[(getCycle()+32)%33] = id689in_input;
  }
  HWFloat<8,24> id610out_output;

  { // Node ID: 610 (NodeStreamOffset)
    const HWFloat<8,24> &id610in_input = id151out_result[getCycle()%2];

    id610out_output = id610in_input;
  }
  { // Node ID: 690 (NodeFIFO)
    const HWFloat<8,24> &id690in_input = id610out_output;

    id690out_output[(getCycle()+12)%13] = id690in_input;
  }
  { // Node ID: 493 (NodeConstantRawBits)
  }
  { // Node ID: 102 (NodeSub)
    const HWOffsetFix<16,0,UNSIGNED> &id102in_a = id790out_value;
    const HWOffsetFix<16,0,UNSIGNED> &id102in_b = id493out_value;

    id102out_result[(getCycle()+1)%2] = (sub_fixed<16,0,UNSIGNED,TONEAREVEN>(id102in_a,id102in_b));
  }
  { // Node ID: 580 (NodeEqInlined)
    const HWOffsetFix<16,0,UNSIGNED> &id580in_a = id613out_output[getCycle()%2];
    const HWOffsetFix<16,0,UNSIGNED> &id580in_b = id102out_result[getCycle()%2];

    id580out_result[(getCycle()+1)%2] = (eq_fixed(id580in_a,id580in_b));
  }
  { // Node ID: 492 (NodeConstantRawBits)
  }
  { // Node ID: 581 (NodeLtInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id581in_a = id612out_output[getCycle()%2];
    const HWOffsetFix<6,0,UNSIGNED> &id581in_b = id492out_value;

    id581out_result[(getCycle()+1)%2] = (lt_fixed(id581in_a,id581in_b));
  }
  { // Node ID: 106 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id106in_a = id580out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id106in_b = id581out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id106x_1;

    (id106x_1) = (and_fixed(id106in_a,id106in_b));
    id106out_result[(getCycle()+1)%2] = (id106x_1);
  }
  { // Node ID: 107 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id108out_result;

  { // Node ID: 108 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id108in_a = id107out_io_Wh_force_disabled;

    id108out_result = (not_fixed(id108in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id109out_result;

  { // Node ID: 109 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id109in_a = id106out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id109in_b = id108out_result;

    HWOffsetFix<1,0,UNSIGNED> id109x_1;

    (id109x_1) = (and_fixed(id109in_a,id109in_b));
    id109out_result = (id109x_1);
  }
  { // Node ID: 685 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id685in_input = id109out_result;

    id685out_output[(getCycle()+35)%36] = id685in_input;
  }
  if ( (getFillLevel() >= (39l)))
  { // Node ID: 110 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id110in_enable = id685out_output[getCycle()%36];

    (id110st_read_next_cycle) = ((id110in_enable.getValueAsBool())&(!(((getFlushLevel())>=(39l))&(isFlushingActive()))));
    queueReadRequest(m_Wh, id110st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 686 (NodeFIFO)
    const HWFloat<8,24> &id686in_input = id59out_result[getCycle()%2];

    id686out_output[(getCycle()+31)%32] = id686in_input;
  }
  { // Node ID: 149 (NodeMul)
    const HWFloat<8,24> &id149in_a = id110out_data;
    const HWFloat<8,24> &id149in_b = id686out_output[getCycle()%32];

    id149out_result[(getCycle()+8)%9] = (mul_float(id149in_a,id149in_b));
  }
  { // Node ID: 491 (NodeConstantRawBits)
  }
  { // Node ID: 582 (NodeEqInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id582in_a = id774out_output[getCycle()%20];
    const HWOffsetFix<6,0,UNSIGNED> &id582in_b = id491out_value;

    id582out_result[(getCycle()+1)%2] = (eq_fixed(id582in_a,id582in_b));
  }
  { // Node ID: 688 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id688in_input = id582out_result[getCycle()%2];

    id688out_output[(getCycle()+20)%21] = id688in_input;
  }
  { // Node ID: 143 (NodeConstantRawBits)
  }
  { // Node ID: 144 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id144in_sel = id688out_output[getCycle()%21];
    const HWFloat<8,24> &id144in_option0 = id610out_output;
    const HWFloat<8,24> &id144in_option1 = id143out_value;

    HWFloat<8,24> id144x_1;

    switch((id144in_sel.getValueAsLong())) {
      case 0l:
        id144x_1 = id144in_option0;
        break;
      case 1l:
        id144x_1 = id144in_option1;
        break;
      default:
        id144x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id144out_result[(getCycle()+1)%2] = (id144x_1);
  }
  { // Node ID: 150 (NodeAdd)
    const HWFloat<8,24> &id150in_a = id149out_result[getCycle()%9];
    const HWFloat<8,24> &id150in_b = id144out_result[getCycle()%2];

    id150out_result[(getCycle()+11)%12] = (add_float(id150in_a,id150in_b));
  }
  { // Node ID: 151 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id151in_sel = id689out_output[getCycle()%33];
    const HWFloat<8,24> &id151in_option0 = id690out_output[getCycle()%13];
    const HWFloat<8,24> &id151in_option1 = id150out_result[getCycle()%12];

    HWFloat<8,24> id151x_1;

    switch((id151in_sel.getValueAsLong())) {
      case 0l:
        id151x_1 = id151in_option0;
        break;
      case 1l:
        id151x_1 = id151in_option1;
        break;
      default:
        id151x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id151out_result[(getCycle()+1)%2] = (id151x_1);
  }
  { // Node ID: 691 (NodeFIFO)
    const HWFloat<8,24> &id691in_input = id151out_result[getCycle()%2];

    id691out_output[(getCycle()+8)%9] = id691in_input;
  }
  { // Node ID: 238 (NodeAdd)
    const HWFloat<8,24> &id238in_a = id237out_result[getCycle()%9];
    const HWFloat<8,24> &id238in_b = id691out_output[getCycle()%9];

    id238out_result[(getCycle()+11)%12] = (add_float(id238in_a,id238in_b));
  }
  { // Node ID: 708 (NodeFIFO)
    const HWFloat<8,24> &id708in_input = id238out_result[getCycle()%12];

    id708out_output[(getCycle()+1)%2] = id708in_input;
  }
  { // Node ID: 781 (NodeFIFO)
    const HWFloat<8,24> &id781in_input = id708out_output[getCycle()%2];

    id781out_output[(getCycle()+1)%2] = id781in_input;
  }
  { // Node ID: 782 (NodeFIFO)
    const HWFloat<8,24> &id782in_input = id781out_output[getCycle()%2];

    id782out_output[(getCycle()+2)%3] = id782in_input;
  }
  { // Node ID: 783 (NodeFIFO)
    const HWFloat<8,24> &id783in_input = id782out_output[getCycle()%3];

    id783out_output[(getCycle()+1)%2] = id783in_input;
  }
  { // Node ID: 784 (NodeFIFO)
    const HWFloat<8,24> &id784in_input = id783out_output[getCycle()%2];

    id784out_output[(getCycle()+1)%2] = id784in_input;
  }
  { // Node ID: 785 (NodeFIFO)
    const HWFloat<8,24> &id785in_input = id784out_output[getCycle()%2];

    id785out_output[(getCycle()+8)%9] = id785in_input;
  }
  { // Node ID: 490 (NodeConstantRawBits)
  }
  { // Node ID: 240 (NodeLte)
    const HWFloat<8,24> &id240in_a = id785out_output[getCycle()%9];
    const HWFloat<8,24> &id240in_b = id490out_value;

    id240out_result[(getCycle()+2)%3] = (lte_float(id240in_a,id240in_b));
  }
  { // Node ID: 720 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id720in_input = id240out_result[getCycle()%3];

    id720out_output[(getCycle()+10)%11] = id720in_input;
  }
  { // Node ID: 489 (NodeConstantRawBits)
  }
  { // Node ID: 242 (NodeGt)
    const HWFloat<8,24> &id242in_a = id785out_output[getCycle()%9];
    const HWFloat<8,24> &id242in_b = id489out_value;

    id242out_result[(getCycle()+2)%3] = (gt_float(id242in_a,id242in_b));
  }
  { // Node ID: 488 (NodeConstantRawBits)
  }
  { // Node ID: 244 (NodeLte)
    const HWFloat<8,24> &id244in_a = id785out_output[getCycle()%9];
    const HWFloat<8,24> &id244in_b = id488out_value;

    id244out_result[(getCycle()+2)%3] = (lte_float(id244in_a,id244in_b));
  }
  { // Node ID: 245 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id245in_a = id242out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id245in_b = id244out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id245x_1;

    (id245x_1) = (and_fixed(id245in_a,id245in_b));
    id245out_result[(getCycle()+1)%2] = (id245x_1);
  }
  { // Node ID: 719 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id719in_input = id245out_result[getCycle()%2];

    id719out_output[(getCycle()+8)%9] = id719in_input;
  }
  { // Node ID: 487 (NodeConstantRawBits)
  }
  { // Node ID: 251 (NodeGt)
    const HWFloat<8,24> &id251in_a = id785out_output[getCycle()%9];
    const HWFloat<8,24> &id251in_b = id487out_value;

    id251out_result[(getCycle()+2)%3] = (gt_float(id251in_a,id251in_b));
  }
  { // Node ID: 486 (NodeConstantRawBits)
  }
  { // Node ID: 253 (NodeLte)
    const HWFloat<8,24> &id253in_a = id785out_output[getCycle()%9];
    const HWFloat<8,24> &id253in_b = id486out_value;

    id253out_result[(getCycle()+2)%3] = (lte_float(id253in_a,id253in_b));
  }
  { // Node ID: 254 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id254in_a = id251out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id254in_b = id253out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id254x_1;

    (id254x_1) = (and_fixed(id254in_a,id254in_b));
    id254out_result[(getCycle()+1)%2] = (id254x_1);
  }
  { // Node ID: 717 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id717in_input = id254out_result[getCycle()%2];

    id717out_output[(getCycle()+7)%8] = id717in_input;
  }
  { // Node ID: 485 (NodeConstantRawBits)
  }
  { // Node ID: 260 (NodeGt)
    const HWFloat<8,24> &id260in_a = id785out_output[getCycle()%9];
    const HWFloat<8,24> &id260in_b = id485out_value;

    id260out_result[(getCycle()+2)%3] = (gt_float(id260in_a,id260in_b));
  }
  { // Node ID: 484 (NodeConstantRawBits)
  }
  { // Node ID: 262 (NodeLte)
    const HWFloat<8,24> &id262in_a = id785out_output[getCycle()%9];
    const HWFloat<8,24> &id262in_b = id484out_value;

    id262out_result[(getCycle()+2)%3] = (lte_float(id262in_a,id262in_b));
  }
  { // Node ID: 263 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id263in_a = id260out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id263in_b = id262out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id263x_1;

    (id263x_1) = (and_fixed(id263in_a,id263in_b));
    id263out_result[(getCycle()+1)%2] = (id263x_1);
  }
  { // Node ID: 715 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id715in_input = id263out_result[getCycle()%2];

    id715out_output[(getCycle()+6)%7] = id715in_input;
  }
  { // Node ID: 483 (NodeConstantRawBits)
  }
  { // Node ID: 269 (NodeGt)
    const HWFloat<8,24> &id269in_a = id785out_output[getCycle()%9];
    const HWFloat<8,24> &id269in_b = id483out_value;

    id269out_result[(getCycle()+2)%3] = (gt_float(id269in_a,id269in_b));
  }
  { // Node ID: 482 (NodeConstantRawBits)
  }
  { // Node ID: 271 (NodeLte)
    const HWFloat<8,24> &id271in_a = id785out_output[getCycle()%9];
    const HWFloat<8,24> &id271in_b = id482out_value;

    id271out_result[(getCycle()+2)%3] = (lte_float(id271in_a,id271in_b));
  }
  { // Node ID: 272 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id272in_a = id269out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id272in_b = id271out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id272x_1;

    (id272x_1) = (and_fixed(id272in_a,id272in_b));
    id272out_result[(getCycle()+1)%2] = (id272x_1);
  }
  { // Node ID: 713 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id713in_input = id272out_result[getCycle()%2];

    id713out_output[(getCycle()+5)%6] = id713in_input;
  }
  { // Node ID: 481 (NodeConstantRawBits)
  }
  { // Node ID: 276 (NodeGt)
    const HWFloat<8,24> &id276in_a = id785out_output[getCycle()%9];
    const HWFloat<8,24> &id276in_b = id481out_value;

    id276out_result[(getCycle()+2)%3] = (gt_float(id276in_a,id276in_b));
  }
  { // Node ID: 480 (NodeConstantRawBits)
  }
  { // Node ID: 278 (NodeLte)
    const HWFloat<8,24> &id278in_a = id785out_output[getCycle()%9];
    const HWFloat<8,24> &id278in_b = id480out_value;

    id278out_result[(getCycle()+2)%3] = (lte_float(id278in_a,id278in_b));
  }
  { // Node ID: 279 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id279in_a = id276out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id279in_b = id278out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id279x_1;

    (id279x_1) = (and_fixed(id279in_a,id279in_b));
    id279out_result[(getCycle()+1)%2] = (id279x_1);
  }
  { // Node ID: 711 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id711in_input = id279out_result[getCycle()%2];

    id711out_output[(getCycle()+4)%5] = id711in_input;
  }
  { // Node ID: 479 (NodeConstantRawBits)
  }
  { // Node ID: 285 (NodeGt)
    const HWFloat<8,24> &id285in_a = id785out_output[getCycle()%9];
    const HWFloat<8,24> &id285in_b = id479out_value;

    id285out_result[(getCycle()+2)%3] = (gt_float(id285in_a,id285in_b));
  }
  { // Node ID: 478 (NodeConstantRawBits)
  }
  { // Node ID: 287 (NodeLte)
    const HWFloat<8,24> &id287in_a = id785out_output[getCycle()%9];
    const HWFloat<8,24> &id287in_b = id478out_value;

    id287out_result[(getCycle()+2)%3] = (lte_float(id287in_a,id287in_b));
  }
  { // Node ID: 288 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id288in_a = id285out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id288in_b = id287out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id288x_1;

    (id288x_1) = (and_fixed(id288in_a,id288in_b));
    id288out_result[(getCycle()+1)%2] = (id288x_1);
  }
  { // Node ID: 709 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id709in_input = id288out_result[getCycle()%2];

    id709out_output[(getCycle()+3)%4] = id709in_input;
  }
  { // Node ID: 477 (NodeConstantRawBits)
  }
  { // Node ID: 294 (NodeGt)
    const HWFloat<8,24> &id294in_a = id785out_output[getCycle()%9];
    const HWFloat<8,24> &id294in_b = id477out_value;

    id294out_result[(getCycle()+2)%3] = (gt_float(id294in_a,id294in_b));
  }
  { // Node ID: 476 (NodeConstantRawBits)
  }
  { // Node ID: 296 (NodeLte)
    const HWFloat<8,24> &id296in_a = id785out_output[getCycle()%9];
    const HWFloat<8,24> &id296in_b = id476out_value;

    id296out_result[(getCycle()+2)%3] = (lte_float(id296in_a,id296in_b));
  }
  { // Node ID: 297 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id297in_a = id294out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id297in_b = id296out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id297x_1;

    (id297x_1) = (and_fixed(id297in_a,id297in_b));
    id297out_result[(getCycle()+1)%2] = (id297x_1);
  }
  { // Node ID: 707 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id707in_input = id297out_result[getCycle()%2];

    id707out_output[(getCycle()+2)%3] = id707in_input;
  }
  { // Node ID: 302 (NodeConstantRawBits)
  }
  { // Node ID: 475 (NodeConstantRawBits)
  }
  { // Node ID: 299 (NodeMul)
    const HWFloat<8,24> &id299in_a = id475out_value;
    const HWFloat<8,24> &id299in_b = id238out_result[getCycle()%12];

    id299out_result[(getCycle()+8)%9] = (mul_float(id299in_a,id299in_b));
  }
  { // Node ID: 474 (NodeConstantRawBits)
  }
  { // Node ID: 301 (NodeAdd)
    const HWFloat<8,24> &id301in_a = id299out_result[getCycle()%9];
    const HWFloat<8,24> &id301in_b = id474out_value;

    id301out_result[(getCycle()+11)%12] = (add_float(id301in_a,id301in_b));
  }
  { // Node ID: 303 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id303in_sel = id707out_output[getCycle()%3];
    const HWFloat<8,24> &id303in_option0 = id302out_value;
    const HWFloat<8,24> &id303in_option1 = id301out_result[getCycle()%12];

    HWFloat<8,24> id303x_1;

    switch((id303in_sel.getValueAsLong())) {
      case 0l:
        id303x_1 = id303in_option0;
        break;
      case 1l:
        id303x_1 = id303in_option1;
        break;
      default:
        id303x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id303out_result[(getCycle()+1)%2] = (id303x_1);
  }
  { // Node ID: 473 (NodeConstantRawBits)
  }
  { // Node ID: 290 (NodeMul)
    const HWFloat<8,24> &id290in_a = id473out_value;
    const HWFloat<8,24> &id290in_b = id708out_output[getCycle()%2];

    id290out_result[(getCycle()+8)%9] = (mul_float(id290in_a,id290in_b));
  }
  { // Node ID: 472 (NodeConstantRawBits)
  }
  { // Node ID: 292 (NodeAdd)
    const HWFloat<8,24> &id292in_a = id290out_result[getCycle()%9];
    const HWFloat<8,24> &id292in_b = id472out_value;

    id292out_result[(getCycle()+11)%12] = (add_float(id292in_a,id292in_b));
  }
  { // Node ID: 304 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id304in_sel = id709out_output[getCycle()%4];
    const HWFloat<8,24> &id304in_option0 = id303out_result[getCycle()%2];
    const HWFloat<8,24> &id304in_option1 = id292out_result[getCycle()%12];

    HWFloat<8,24> id304x_1;

    switch((id304in_sel.getValueAsLong())) {
      case 0l:
        id304x_1 = id304in_option0;
        break;
      case 1l:
        id304x_1 = id304in_option1;
        break;
      default:
        id304x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id304out_result[(getCycle()+1)%2] = (id304x_1);
  }
  { // Node ID: 471 (NodeConstantRawBits)
  }
  { // Node ID: 281 (NodeMul)
    const HWFloat<8,24> &id281in_a = id471out_value;
    const HWFloat<8,24> &id281in_b = id781out_output[getCycle()%2];

    id281out_result[(getCycle()+8)%9] = (mul_float(id281in_a,id281in_b));
  }
  { // Node ID: 470 (NodeConstantRawBits)
  }
  { // Node ID: 283 (NodeAdd)
    const HWFloat<8,24> &id283in_a = id281out_result[getCycle()%9];
    const HWFloat<8,24> &id283in_b = id470out_value;

    id283out_result[(getCycle()+11)%12] = (add_float(id283in_a,id283in_b));
  }
  { // Node ID: 305 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id305in_sel = id711out_output[getCycle()%5];
    const HWFloat<8,24> &id305in_option0 = id304out_result[getCycle()%2];
    const HWFloat<8,24> &id305in_option1 = id283out_result[getCycle()%12];

    HWFloat<8,24> id305x_1;

    switch((id305in_sel.getValueAsLong())) {
      case 0l:
        id305x_1 = id305in_option0;
        break;
      case 1l:
        id305x_1 = id305in_option1;
        break;
      default:
        id305x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id305out_result[(getCycle()+1)%2] = (id305x_1);
  }
  { // Node ID: 469 (NodeConstantRawBits)
  }
  { // Node ID: 274 (NodeMul)
    const HWFloat<8,24> &id274in_a = id469out_value;
    const HWFloat<8,24> &id274in_b = id785out_output[getCycle()%9];

    id274out_result[(getCycle()+8)%9] = (mul_float(id274in_a,id274in_b));
  }
  { // Node ID: 306 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id306in_sel = id713out_output[getCycle()%6];
    const HWFloat<8,24> &id306in_option0 = id305out_result[getCycle()%2];
    const HWFloat<8,24> &id306in_option1 = id274out_result[getCycle()%9];

    HWFloat<8,24> id306x_1;

    switch((id306in_sel.getValueAsLong())) {
      case 0l:
        id306x_1 = id306in_option0;
        break;
      case 1l:
        id306x_1 = id306in_option1;
        break;
      default:
        id306x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id306out_result[(getCycle()+1)%2] = (id306x_1);
  }
  { // Node ID: 468 (NodeConstantRawBits)
  }
  { // Node ID: 265 (NodeMul)
    const HWFloat<8,24> &id265in_a = id468out_value;
    const HWFloat<8,24> &id265in_b = id782out_output[getCycle()%3];

    id265out_result[(getCycle()+8)%9] = (mul_float(id265in_a,id265in_b));
  }
  { // Node ID: 467 (NodeConstantRawBits)
  }
  { // Node ID: 267 (NodeSub)
    const HWFloat<8,24> &id267in_a = id265out_result[getCycle()%9];
    const HWFloat<8,24> &id267in_b = id467out_value;

    id267out_result[(getCycle()+11)%12] = (sub_float(id267in_a,id267in_b));
  }
  { // Node ID: 307 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id307in_sel = id715out_output[getCycle()%7];
    const HWFloat<8,24> &id307in_option0 = id306out_result[getCycle()%2];
    const HWFloat<8,24> &id307in_option1 = id267out_result[getCycle()%12];

    HWFloat<8,24> id307x_1;

    switch((id307in_sel.getValueAsLong())) {
      case 0l:
        id307x_1 = id307in_option0;
        break;
      case 1l:
        id307x_1 = id307in_option1;
        break;
      default:
        id307x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id307out_result[(getCycle()+1)%2] = (id307x_1);
  }
  { // Node ID: 466 (NodeConstantRawBits)
  }
  { // Node ID: 256 (NodeMul)
    const HWFloat<8,24> &id256in_a = id466out_value;
    const HWFloat<8,24> &id256in_b = id783out_output[getCycle()%2];

    id256out_result[(getCycle()+8)%9] = (mul_float(id256in_a,id256in_b));
  }
  { // Node ID: 465 (NodeConstantRawBits)
  }
  { // Node ID: 258 (NodeSub)
    const HWFloat<8,24> &id258in_a = id256out_result[getCycle()%9];
    const HWFloat<8,24> &id258in_b = id465out_value;

    id258out_result[(getCycle()+11)%12] = (sub_float(id258in_a,id258in_b));
  }
  { // Node ID: 308 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id308in_sel = id717out_output[getCycle()%8];
    const HWFloat<8,24> &id308in_option0 = id307out_result[getCycle()%2];
    const HWFloat<8,24> &id308in_option1 = id258out_result[getCycle()%12];

    HWFloat<8,24> id308x_1;

    switch((id308in_sel.getValueAsLong())) {
      case 0l:
        id308x_1 = id308in_option0;
        break;
      case 1l:
        id308x_1 = id308in_option1;
        break;
      default:
        id308x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id308out_result[(getCycle()+1)%2] = (id308x_1);
  }
  { // Node ID: 464 (NodeConstantRawBits)
  }
  { // Node ID: 247 (NodeMul)
    const HWFloat<8,24> &id247in_a = id464out_value;
    const HWFloat<8,24> &id247in_b = id784out_output[getCycle()%2];

    id247out_result[(getCycle()+8)%9] = (mul_float(id247in_a,id247in_b));
  }
  { // Node ID: 463 (NodeConstantRawBits)
  }
  { // Node ID: 249 (NodeSub)
    const HWFloat<8,24> &id249in_a = id247out_result[getCycle()%9];
    const HWFloat<8,24> &id249in_b = id463out_value;

    id249out_result[(getCycle()+11)%12] = (sub_float(id249in_a,id249in_b));
  }
  { // Node ID: 309 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id309in_sel = id719out_output[getCycle()%9];
    const HWFloat<8,24> &id309in_option0 = id308out_result[getCycle()%2];
    const HWFloat<8,24> &id309in_option1 = id249out_result[getCycle()%12];

    HWFloat<8,24> id309x_1;

    switch((id309in_sel.getValueAsLong())) {
      case 0l:
        id309x_1 = id309in_option0;
        break;
      case 1l:
        id309x_1 = id309in_option1;
        break;
      default:
        id309x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id309out_result[(getCycle()+1)%2] = (id309x_1);
  }
  { // Node ID: 310 (NodeConstantRawBits)
  }
  { // Node ID: 311 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id311in_sel = id720out_output[getCycle()%11];
    const HWFloat<8,24> &id311in_option0 = id309out_result[getCycle()%2];
    const HWFloat<8,24> &id311in_option1 = id310out_value;

    HWFloat<8,24> id311x_1;

    switch((id311in_sel.getValueAsLong())) {
      case 0l:
        id311x_1 = id311in_option0;
        break;
      case 1l:
        id311x_1 = id311in_option1;
        break;
      default:
        id311x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id311out_result[(getCycle()+1)%2] = (id311x_1);
  }
  { // Node ID: 313 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id313in_sel = id721out_output[getCycle()%107];
    const HWFloat<8,24> &id313in_option0 = id312out_value;
    const HWFloat<8,24> &id313in_option1 = id311out_result[getCycle()%2];

    HWFloat<8,24> id313x_1;

    switch((id313in_sel.getValueAsLong())) {
      case 0l:
        id313x_1 = id313in_option0;
        break;
      case 1l:
        id313x_1 = id313in_option1;
        break;
      default:
        id313x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id313out_result[(getCycle()+1)%2] = (id313x_1);
  }
  { // Node ID: 462 (NodeConstantRawBits)
  }
  { // Node ID: 461 (NodeConstantRawBits)
  }
  { // Node ID: 315 (NodeSub)
    const HWOffsetFix<6,0,UNSIGNED> &id315in_a = id0out_hsize;
    const HWOffsetFix<6,0,UNSIGNED> &id315in_b = id461out_value;

    id315out_result[(getCycle()+1)%2] = (sub_fixed<6,0,UNSIGNED,TONEAREVEN>(id315in_a,id315in_b));
  }
  { // Node ID: 583 (NodeEqInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id583in_a = id612out_output[getCycle()%2];
    const HWOffsetFix<6,0,UNSIGNED> &id583in_b = id315out_result[getCycle()%2];

    id583out_result[(getCycle()+1)%2] = (eq_fixed(id583in_a,id583in_b));
  }
  { // Node ID: 460 (NodeConstantRawBits)
  }
  { // Node ID: 318 (NodeSub)
    const HWOffsetFix<16,0,UNSIGNED> &id318in_a = id790out_value;
    const HWOffsetFix<16,0,UNSIGNED> &id318in_b = id460out_value;

    id318out_result[(getCycle()+1)%2] = (sub_fixed<16,0,UNSIGNED,TONEAREVEN>(id318in_a,id318in_b));
  }
  { // Node ID: 584 (NodeEqInlined)
    const HWOffsetFix<16,0,UNSIGNED> &id584in_a = id613out_output[getCycle()%2];
    const HWOffsetFix<16,0,UNSIGNED> &id584in_b = id318out_result[getCycle()%2];

    id584out_result[(getCycle()+1)%2] = (eq_fixed(id584in_a,id584in_b));
  }
  { // Node ID: 320 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id320in_a = id583out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id320in_b = id584out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id320x_1;

    (id320x_1) = (and_fixed(id320in_a,id320in_b));
    id320out_result[(getCycle()+1)%2] = (id320x_1);
  }
  { // Node ID: 761 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id761in_input = id320out_result[getCycle()%2];

    id761out_output[(getCycle()+90)%91] = id761in_input;
  }
  { // Node ID: 386 (NodeConstantRawBits)
  }
  { // Node ID: 459 (NodeConstantRawBits)
  }
  { // Node ID: 585 (NodeLtInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id585in_a = id774out_output[getCycle()%20];
    const HWOffsetFix<6,0,UNSIGNED> &id585in_b = id459out_value;

    id585out_result[(getCycle()+1)%2] = (lt_fixed(id585in_a,id585in_b));
  }
  { // Node ID: 735 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id735in_input = id585out_result[getCycle()%2];

    id735out_output[(getCycle()+43)%44] = id735in_input;
  }
  { // Node ID: 458 (NodeConstantRawBits)
  }
  { // Node ID: 61 (NodeSub)
    const HWOffsetFix<16,0,UNSIGNED> &id61in_a = id790out_value;
    const HWOffsetFix<16,0,UNSIGNED> &id61in_b = id458out_value;

    id61out_result[(getCycle()+1)%2] = (sub_fixed<16,0,UNSIGNED,TONEAREVEN>(id61in_a,id61in_b));
  }
  { // Node ID: 586 (NodeEqInlined)
    const HWOffsetFix<16,0,UNSIGNED> &id586in_a = id613out_output[getCycle()%2];
    const HWOffsetFix<16,0,UNSIGNED> &id586in_b = id61out_result[getCycle()%2];

    id586out_result[(getCycle()+1)%2] = (eq_fixed(id586in_a,id586in_b));
  }
  { // Node ID: 63 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id64out_result;

  { // Node ID: 64 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id64in_a = id63out_io_Uz_force_disabled;

    id64out_result = (not_fixed(id64in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id65out_result;

  { // Node ID: 65 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id65in_a = id586out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id65in_b = id64out_result;

    HWOffsetFix<1,0,UNSIGNED> id65x_1;

    (id65x_1) = (and_fixed(id65in_a,id65in_b));
    id65out_result = (id65x_1);
  }
  { // Node ID: 726 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id726in_input = id65out_result;

    id726out_output[(getCycle()+36)%37] = id726in_input;
  }
  if ( (getFillLevel() >= (39l)))
  { // Node ID: 66 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id66in_enable = id726out_output[getCycle()%37];

    (id66st_read_next_cycle) = ((id66in_enable.getValueAsBool())&(!(((getFlushLevel())>=(39l))&(isFlushingActive()))));
    queueReadRequest(m_Uz, id66st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 121 (NodeMul)
    const HWFloat<8,24> &id121in_a = id66out_data;
    const HWFloat<8,24> &id121in_b = id677out_output[getCycle()%32];

    id121out_result[(getCycle()+8)%9] = (mul_float(id121in_a,id121in_b));
  }
  { // Node ID: 730 (NodeFIFO)
    const HWFloat<8,24> &id730in_input = id121out_result[getCycle()%9];

    id730out_output[(getCycle()+11)%12] = id730in_input;
  }
  { // Node ID: 457 (NodeConstantRawBits)
  }
  { // Node ID: 587 (NodeEqInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id587in_a = id774out_output[getCycle()%20];
    const HWOffsetFix<6,0,UNSIGNED> &id587in_b = id457out_value;

    id587out_result[(getCycle()+1)%2] = (eq_fixed(id587in_a,id587in_b));
  }
  { // Node ID: 729 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id729in_input = id587out_result[getCycle()%2];

    id729out_output[(getCycle()+31)%32] = id729in_input;
  }
  HWFloat<8,24> id611out_output;

  { // Node ID: 611 (NodeStreamOffset)
    const HWFloat<8,24> &id611in_input = id123out_result[getCycle()%2];

    id611out_output = id611in_input;
  }
  { // Node ID: 113 (NodeConstantRawBits)
  }
  { // Node ID: 114 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id114in_sel = id729out_output[getCycle()%32];
    const HWFloat<8,24> &id114in_option0 = id611out_output;
    const HWFloat<8,24> &id114in_option1 = id113out_value;

    HWFloat<8,24> id114x_1;

    switch((id114in_sel.getValueAsLong())) {
      case 0l:
        id114x_1 = id114in_option0;
        break;
      case 1l:
        id114x_1 = id114in_option1;
        break;
      default:
        id114x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id114out_result[(getCycle()+1)%2] = (id114x_1);
  }
  { // Node ID: 122 (NodeAdd)
    const HWFloat<8,24> &id122in_a = id730out_output[getCycle()%12];
    const HWFloat<8,24> &id122in_b = id114out_result[getCycle()%2];

    id122out_result[(getCycle()+11)%12] = (add_float(id122in_a,id122in_b));
  }
  { // Node ID: 456 (NodeConstantRawBits)
  }
  { // Node ID: 68 (NodeSub)
    const HWOffsetFix<16,0,UNSIGNED> &id68in_a = id790out_value;
    const HWOffsetFix<16,0,UNSIGNED> &id68in_b = id456out_value;

    id68out_result[(getCycle()+1)%2] = (sub_fixed<16,0,UNSIGNED,TONEAREVEN>(id68in_a,id68in_b));
  }
  { // Node ID: 588 (NodeEqInlined)
    const HWOffsetFix<16,0,UNSIGNED> &id588in_a = id613out_output[getCycle()%2];
    const HWOffsetFix<16,0,UNSIGNED> &id588in_b = id68out_result[getCycle()%2];

    id588out_result[(getCycle()+1)%2] = (eq_fixed(id588in_a,id588in_b));
  }
  { // Node ID: 455 (NodeConstantRawBits)
  }
  { // Node ID: 589 (NodeLtInlined)
    const HWOffsetFix<6,0,UNSIGNED> &id589in_a = id612out_output[getCycle()%2];
    const HWOffsetFix<6,0,UNSIGNED> &id589in_b = id455out_value;

    id589out_result[(getCycle()+1)%2] = (lt_fixed(id589in_a,id589in_b));
  }
  { // Node ID: 72 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id72in_a = id588out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id72in_b = id589out_result[getCycle()%2];

    HWOffsetFix<1,0,UNSIGNED> id72x_1;

    (id72x_1) = (and_fixed(id72in_a,id72in_b));
    id72out_result[(getCycle()+1)%2] = (id72x_1);
  }
  { // Node ID: 73 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id74out_result;

  { // Node ID: 74 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id74in_a = id73out_io_Wz_force_disabled;

    id74out_result = (not_fixed(id74in_a));
  }
  HWOffsetFix<1,0,UNSIGNED> id75out_result;

  { // Node ID: 75 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id75in_a = id72out_result[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id75in_b = id74out_result;

    HWOffsetFix<1,0,UNSIGNED> id75x_1;

    (id75x_1) = (and_fixed(id75in_a,id75in_b));
    id75out_result = (id75x_1);
  }
  { // Node ID: 733 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id733in_input = id75out_result;

    id733out_output[(getCycle()+35)%36] = id733in_input;
  }
  if ( (getFillLevel() >= (39l)))
  { // Node ID: 76 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id76in_enable = id733out_output[getCycle()%36];

    (id76st_read_next_cycle) = ((id76in_enable.getValueAsBool())&(!(((getFlushLevel())>=(39l))&(isFlushingActive()))));
    queueReadRequest(m_Wz, id76st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 118 (NodeMul)
    const HWFloat<8,24> &id118in_a = id76out_data;
    const HWFloat<8,24> &id118in_b = id686out_output[getCycle()%32];

    id118out_result[(getCycle()+8)%9] = (mul_float(id118in_a,id118in_b));
  }
  { // Node ID: 119 (NodeAdd)
    const HWFloat<8,24> &id119in_a = id121out_result[getCycle()%9];
    const HWFloat<8,24> &id119in_b = id118out_result[getCycle()%9];

    id119out_result[(getCycle()+11)%12] = (add_float(id119in_a,id119in_b));
  }
  { // Node ID: 120 (NodeAdd)
    const HWFloat<8,24> &id120in_a = id119out_result[getCycle()%12];
    const HWFloat<8,24> &id120in_b = id114out_result[getCycle()%2];

    id120out_result[(getCycle()+11)%12] = (add_float(id120in_a,id120in_b));
  }
  { // Node ID: 123 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id123in_sel = id735out_output[getCycle()%44];
    const HWFloat<8,24> &id123in_option0 = id122out_result[getCycle()%12];
    const HWFloat<8,24> &id123in_option1 = id120out_result[getCycle()%12];

    HWFloat<8,24> id123x_1;

    switch((id123in_sel.getValueAsLong())) {
      case 0l:
        id123x_1 = id123in_option0;
        break;
      case 1l:
        id123x_1 = id123in_option1;
        break;
      default:
        id123x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id123out_result[(getCycle()+1)%2] = (id123x_1);
  }
  { // Node ID: 750 (NodeFIFO)
    const HWFloat<8,24> &id750in_input = id123out_result[getCycle()%2];

    id750out_output[(getCycle()+1)%2] = id750in_input;
  }
  { // Node ID: 786 (NodeFIFO)
    const HWFloat<8,24> &id786in_input = id750out_output[getCycle()%2];

    id786out_output[(getCycle()+1)%2] = id786in_input;
  }
  { // Node ID: 787 (NodeFIFO)
    const HWFloat<8,24> &id787in_input = id786out_output[getCycle()%2];

    id787out_output[(getCycle()+1)%2] = id787in_input;
  }
  { // Node ID: 788 (NodeFIFO)
    const HWFloat<8,24> &id788in_input = id787out_output[getCycle()%2];

    id788out_output[(getCycle()+1)%2] = id788in_input;
  }
  { // Node ID: 789 (NodeFIFO)
    const HWFloat<8,24> &id789in_input = id788out_output[getCycle()%2];

    id789out_output[(getCycle()+1)%2] = id789in_input;
  }
  { // Node ID: 454 (NodeConstantRawBits)
  }
  { // Node ID: 322 (NodeLt)
    const HWFloat<8,24> &id322in_a = id789out_output[getCycle()%2];
    const HWFloat<8,24> &id322in_b = id454out_value;

    id322out_result[(getCycle()+2)%3] = (lt_float(id322in_a,id322in_b));
  }
  { // Node ID: 760 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id760in_input = id322out_result[getCycle()%3];

    id760out_output[(getCycle()+11)%12] = id760in_input;
  }
  { // Node ID: 453 (NodeConstantRawBits)
  }
  { // Node ID: 324 (NodeGte)
    const HWFloat<8,24> &id324in_a = id789out_output[getCycle()%2];
    const HWFloat<8,24> &id324in_b = id453out_value;

    id324out_result[(getCycle()+2)%3] = (gte_float(id324in_a,id324in_b));
  }
  { // Node ID: 452 (NodeConstantRawBits)
  }
  { // Node ID: 326 (NodeLt)
    const HWFloat<8,24> &id326in_a = id789out_output[getCycle()%2];
    const HWFloat<8,24> &id326in_b = id452out_value;

    id326out_result[(getCycle()+2)%3] = (lt_float(id326in_a,id326in_b));
  }
  { // Node ID: 327 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id327in_a = id324out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id327in_b = id326out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id327x_1;

    (id327x_1) = (and_fixed(id327in_a,id327in_b));
    id327out_result[(getCycle()+1)%2] = (id327x_1);
  }
  { // Node ID: 759 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id759in_input = id327out_result[getCycle()%2];

    id759out_output[(getCycle()+9)%10] = id759in_input;
  }
  { // Node ID: 451 (NodeConstantRawBits)
  }
  { // Node ID: 333 (NodeGte)
    const HWFloat<8,24> &id333in_a = id789out_output[getCycle()%2];
    const HWFloat<8,24> &id333in_b = id451out_value;

    id333out_result[(getCycle()+2)%3] = (gte_float(id333in_a,id333in_b));
  }
  { // Node ID: 450 (NodeConstantRawBits)
  }
  { // Node ID: 335 (NodeLt)
    const HWFloat<8,24> &id335in_a = id789out_output[getCycle()%2];
    const HWFloat<8,24> &id335in_b = id450out_value;

    id335out_result[(getCycle()+2)%3] = (lt_float(id335in_a,id335in_b));
  }
  { // Node ID: 336 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id336in_a = id333out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id336in_b = id335out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id336x_1;

    (id336x_1) = (and_fixed(id336in_a,id336in_b));
    id336out_result[(getCycle()+1)%2] = (id336x_1);
  }
  { // Node ID: 757 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id757in_input = id336out_result[getCycle()%2];

    id757out_output[(getCycle()+8)%9] = id757in_input;
  }
  { // Node ID: 449 (NodeConstantRawBits)
  }
  { // Node ID: 342 (NodeGte)
    const HWFloat<8,24> &id342in_a = id789out_output[getCycle()%2];
    const HWFloat<8,24> &id342in_b = id449out_value;

    id342out_result[(getCycle()+2)%3] = (gte_float(id342in_a,id342in_b));
  }
  { // Node ID: 448 (NodeConstantRawBits)
  }
  { // Node ID: 344 (NodeLt)
    const HWFloat<8,24> &id344in_a = id789out_output[getCycle()%2];
    const HWFloat<8,24> &id344in_b = id448out_value;

    id344out_result[(getCycle()+2)%3] = (lt_float(id344in_a,id344in_b));
  }
  { // Node ID: 345 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id345in_a = id342out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id345in_b = id344out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id345x_1;

    (id345x_1) = (and_fixed(id345in_a,id345in_b));
    id345out_result[(getCycle()+1)%2] = (id345x_1);
  }
  { // Node ID: 755 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id755in_input = id345out_result[getCycle()%2];

    id755out_output[(getCycle()+7)%8] = id755in_input;
  }
  { // Node ID: 447 (NodeConstantRawBits)
  }
  { // Node ID: 351 (NodeGte)
    const HWFloat<8,24> &id351in_a = id789out_output[getCycle()%2];
    const HWFloat<8,24> &id351in_b = id447out_value;

    id351out_result[(getCycle()+2)%3] = (gte_float(id351in_a,id351in_b));
  }
  { // Node ID: 446 (NodeConstantRawBits)
  }
  { // Node ID: 353 (NodeLt)
    const HWFloat<8,24> &id353in_a = id789out_output[getCycle()%2];
    const HWFloat<8,24> &id353in_b = id446out_value;

    id353out_result[(getCycle()+2)%3] = (lt_float(id353in_a,id353in_b));
  }
  { // Node ID: 354 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id354in_a = id351out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id354in_b = id353out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id354x_1;

    (id354x_1) = (and_fixed(id354in_a,id354in_b));
    id354out_result[(getCycle()+1)%2] = (id354x_1);
  }
  { // Node ID: 753 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id753in_input = id354out_result[getCycle()%2];

    id753out_output[(getCycle()+6)%7] = id753in_input;
  }
  { // Node ID: 445 (NodeConstantRawBits)
  }
  { // Node ID: 360 (NodeGte)
    const HWFloat<8,24> &id360in_a = id789out_output[getCycle()%2];
    const HWFloat<8,24> &id360in_b = id445out_value;

    id360out_result[(getCycle()+2)%3] = (gte_float(id360in_a,id360in_b));
  }
  { // Node ID: 444 (NodeConstantRawBits)
  }
  { // Node ID: 362 (NodeLt)
    const HWFloat<8,24> &id362in_a = id789out_output[getCycle()%2];
    const HWFloat<8,24> &id362in_b = id444out_value;

    id362out_result[(getCycle()+2)%3] = (lt_float(id362in_a,id362in_b));
  }
  { // Node ID: 363 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id363in_a = id360out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id363in_b = id362out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id363x_1;

    (id363x_1) = (and_fixed(id363in_a,id363in_b));
    id363out_result[(getCycle()+1)%2] = (id363x_1);
  }
  { // Node ID: 751 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id751in_input = id363out_result[getCycle()%2];

    id751out_output[(getCycle()+5)%6] = id751in_input;
  }
  { // Node ID: 443 (NodeConstantRawBits)
  }
  { // Node ID: 369 (NodeGte)
    const HWFloat<8,24> &id369in_a = id789out_output[getCycle()%2];
    const HWFloat<8,24> &id369in_b = id443out_value;

    id369out_result[(getCycle()+2)%3] = (gte_float(id369in_a,id369in_b));
  }
  { // Node ID: 442 (NodeConstantRawBits)
  }
  { // Node ID: 371 (NodeLt)
    const HWFloat<8,24> &id371in_a = id789out_output[getCycle()%2];
    const HWFloat<8,24> &id371in_b = id442out_value;

    id371out_result[(getCycle()+2)%3] = (lt_float(id371in_a,id371in_b));
  }
  { // Node ID: 372 (NodeAnd)
    const HWOffsetFix<1,0,UNSIGNED> &id372in_a = id369out_result[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id372in_b = id371out_result[getCycle()%3];

    HWOffsetFix<1,0,UNSIGNED> id372x_1;

    (id372x_1) = (and_fixed(id372in_a,id372in_b));
    id372out_result[(getCycle()+1)%2] = (id372x_1);
  }
  { // Node ID: 749 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id749in_input = id372out_result[getCycle()%2];

    id749out_output[(getCycle()+4)%5] = id749in_input;
  }
  { // Node ID: 377 (NodeConstantRawBits)
  }
  { // Node ID: 597 (NodePO2FPMult)
    const HWFloat<8,24> &id597in_floatIn = id123out_result[getCycle()%2];

    id597out_floatOut[(getCycle()+1)%2] = (mul_float(id597in_floatIn,(c_hw_flt_8_24_0_03125val)));
  }
  { // Node ID: 440 (NodeConstantRawBits)
  }
  { // Node ID: 376 (NodeAdd)
    const HWFloat<8,24> &id376in_a = id597out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id376in_b = id440out_value;

    id376out_result[(getCycle()+11)%12] = (add_float(id376in_a,id376in_b));
  }
  { // Node ID: 378 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id378in_sel = id749out_output[getCycle()%5];
    const HWFloat<8,24> &id378in_option0 = id377out_value;
    const HWFloat<8,24> &id378in_option1 = id376out_result[getCycle()%12];

    HWFloat<8,24> id378x_1;

    switch((id378in_sel.getValueAsLong())) {
      case 0l:
        id378x_1 = id378in_option0;
        break;
      case 1l:
        id378x_1 = id378in_option1;
        break;
      default:
        id378x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id378out_result[(getCycle()+1)%2] = (id378x_1);
  }
  { // Node ID: 598 (NodePO2FPMult)
    const HWFloat<8,24> &id598in_floatIn = id750out_output[getCycle()%2];

    id598out_floatOut[(getCycle()+1)%2] = (mul_float(id598in_floatIn,(c_hw_flt_8_24_0_125val)));
  }
  { // Node ID: 438 (NodeConstantRawBits)
  }
  { // Node ID: 367 (NodeAdd)
    const HWFloat<8,24> &id367in_a = id598out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id367in_b = id438out_value;

    id367out_result[(getCycle()+11)%12] = (add_float(id367in_a,id367in_b));
  }
  { // Node ID: 379 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id379in_sel = id751out_output[getCycle()%6];
    const HWFloat<8,24> &id379in_option0 = id378out_result[getCycle()%2];
    const HWFloat<8,24> &id379in_option1 = id367out_result[getCycle()%12];

    HWFloat<8,24> id379x_1;

    switch((id379in_sel.getValueAsLong())) {
      case 0l:
        id379x_1 = id379in_option0;
        break;
      case 1l:
        id379x_1 = id379in_option1;
        break;
      default:
        id379x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id379out_result[(getCycle()+1)%2] = (id379x_1);
  }
  { // Node ID: 599 (NodePO2FPMult)
    const HWFloat<8,24> &id599in_floatIn = id786out_output[getCycle()%2];

    id599out_floatOut[(getCycle()+1)%2] = (mul_float(id599in_floatIn,(c_hw_flt_8_24_0_25val)));
  }
  { // Node ID: 436 (NodeConstantRawBits)
  }
  { // Node ID: 358 (NodeAdd)
    const HWFloat<8,24> &id358in_a = id599out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id358in_b = id436out_value;

    id358out_result[(getCycle()+11)%12] = (add_float(id358in_a,id358in_b));
  }
  { // Node ID: 380 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id380in_sel = id753out_output[getCycle()%7];
    const HWFloat<8,24> &id380in_option0 = id379out_result[getCycle()%2];
    const HWFloat<8,24> &id380in_option1 = id358out_result[getCycle()%12];

    HWFloat<8,24> id380x_1;

    switch((id380in_sel.getValueAsLong())) {
      case 0l:
        id380x_1 = id380in_option0;
        break;
      case 1l:
        id380x_1 = id380in_option1;
        break;
      default:
        id380x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id380out_result[(getCycle()+1)%2] = (id380x_1);
  }
  { // Node ID: 600 (NodePO2FPMult)
    const HWFloat<8,24> &id600in_floatIn = id787out_output[getCycle()%2];

    id600out_floatOut[(getCycle()+1)%2] = (mul_float(id600in_floatIn,(c_hw_flt_8_24_0_25val)));
  }
  { // Node ID: 434 (NodeConstantRawBits)
  }
  { // Node ID: 349 (NodeAdd)
    const HWFloat<8,24> &id349in_a = id600out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id349in_b = id434out_value;

    id349out_result[(getCycle()+11)%12] = (add_float(id349in_a,id349in_b));
  }
  { // Node ID: 381 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id381in_sel = id755out_output[getCycle()%8];
    const HWFloat<8,24> &id381in_option0 = id380out_result[getCycle()%2];
    const HWFloat<8,24> &id381in_option1 = id349out_result[getCycle()%12];

    HWFloat<8,24> id381x_1;

    switch((id381in_sel.getValueAsLong())) {
      case 0l:
        id381x_1 = id381in_option0;
        break;
      case 1l:
        id381x_1 = id381in_option1;
        break;
      default:
        id381x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id381out_result[(getCycle()+1)%2] = (id381x_1);
  }
  { // Node ID: 601 (NodePO2FPMult)
    const HWFloat<8,24> &id601in_floatIn = id788out_output[getCycle()%2];

    id601out_floatOut[(getCycle()+1)%2] = (mul_float(id601in_floatIn,(c_hw_flt_8_24_0_125val)));
  }
  { // Node ID: 432 (NodeConstantRawBits)
  }
  { // Node ID: 340 (NodeAdd)
    const HWFloat<8,24> &id340in_a = id601out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id340in_b = id432out_value;

    id340out_result[(getCycle()+11)%12] = (add_float(id340in_a,id340in_b));
  }
  { // Node ID: 382 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id382in_sel = id757out_output[getCycle()%9];
    const HWFloat<8,24> &id382in_option0 = id381out_result[getCycle()%2];
    const HWFloat<8,24> &id382in_option1 = id340out_result[getCycle()%12];

    HWFloat<8,24> id382x_1;

    switch((id382in_sel.getValueAsLong())) {
      case 0l:
        id382x_1 = id382in_option0;
        break;
      case 1l:
        id382x_1 = id382in_option1;
        break;
      default:
        id382x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id382out_result[(getCycle()+1)%2] = (id382x_1);
  }
  { // Node ID: 602 (NodePO2FPMult)
    const HWFloat<8,24> &id602in_floatIn = id789out_output[getCycle()%2];

    id602out_floatOut[(getCycle()+1)%2] = (mul_float(id602in_floatIn,(c_hw_flt_8_24_0_03125val)));
  }
  { // Node ID: 430 (NodeConstantRawBits)
  }
  { // Node ID: 331 (NodeAdd)
    const HWFloat<8,24> &id331in_a = id602out_floatOut[getCycle()%2];
    const HWFloat<8,24> &id331in_b = id430out_value;

    id331out_result[(getCycle()+11)%12] = (add_float(id331in_a,id331in_b));
  }
  { // Node ID: 383 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id383in_sel = id759out_output[getCycle()%10];
    const HWFloat<8,24> &id383in_option0 = id382out_result[getCycle()%2];
    const HWFloat<8,24> &id383in_option1 = id331out_result[getCycle()%12];

    HWFloat<8,24> id383x_1;

    switch((id383in_sel.getValueAsLong())) {
      case 0l:
        id383x_1 = id383in_option0;
        break;
      case 1l:
        id383x_1 = id383in_option1;
        break;
      default:
        id383x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id383out_result[(getCycle()+1)%2] = (id383x_1);
  }
  { // Node ID: 384 (NodeConstantRawBits)
  }
  { // Node ID: 385 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id385in_sel = id760out_output[getCycle()%12];
    const HWFloat<8,24> &id385in_option0 = id383out_result[getCycle()%2];
    const HWFloat<8,24> &id385in_option1 = id384out_value;

    HWFloat<8,24> id385x_1;

    switch((id385in_sel.getValueAsLong())) {
      case 0l:
        id385x_1 = id385in_option0;
        break;
      case 1l:
        id385x_1 = id385in_option1;
        break;
      default:
        id385x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id385out_result[(getCycle()+1)%2] = (id385x_1);
  }
  { // Node ID: 387 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id387in_sel = id761out_output[getCycle()%91];
    const HWFloat<8,24> &id387in_option0 = id386out_value;
    const HWFloat<8,24> &id387in_option1 = id385out_result[getCycle()%2];

    HWFloat<8,24> id387x_1;

    switch((id387in_sel.getValueAsLong())) {
      case 0l:
        id387x_1 = id387in_option0;
        break;
      case 1l:
        id387x_1 = id387in_option1;
        break;
      default:
        id387x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id387out_result[(getCycle()+1)%2] = (id387x_1);
  }
  { // Node ID: 396 (NodeSub)
    const HWFloat<8,24> &id396in_a = id462out_value;
    const HWFloat<8,24> &id396in_b = id387out_result[getCycle()%2];

    id396out_result[(getCycle()+11)%12] = (sub_float(id396in_a,id396in_b));
  }
  { // Node ID: 762 (NodeFIFO)
    const HWFloat<8,24> &id762in_input = id396out_result[getCycle()%12];

    id762out_output[(getCycle()+5)%6] = id762in_input;
  }
  { // Node ID: 397 (NodeMul)
    const HWFloat<8,24> &id397in_a = id313out_result[getCycle()%2];
    const HWFloat<8,24> &id397in_b = id762out_output[getCycle()%6];

    id397out_result[(getCycle()+8)%9] = (mul_float(id397in_a,id397in_b));
  }
  { // Node ID: 776 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id776in_input = id629out_output[getCycle()%6];

    id776out_output[(getCycle()+2)%3] = id776in_input;
  }
  { // Node ID: 775 (NodeFIFO)
    const HWOffsetFix<6,0,UNSIGNED> &id775in_input = id624out_output[getCycle()%2];

    id775out_output[(getCycle()+9)%10] = id775in_input;
  }
  if ( (getFillLevel() >= (11l)))
  { // Node ID: 414 (NodeRAM)
    const bool id414_inputvalid = !(isFlushingActive() && getFlushLevel() >= (11l));
    const HWOffsetFix<6,0,UNSIGNED> &id414in_addrA = id773out_output[getCycle()%3];
    const HWFloat<8,24> &id414in_dina = id632out_output[getCycle()%3];
    const HWOffsetFix<1,0,UNSIGNED> &id414in_wea = id776out_output[getCycle()%3];
    const HWOffsetFix<6,0,UNSIGNED> &id414in_addrB = id775out_output[getCycle()%10];

    long id414x_1;
    long id414x_2;
    HWFloat<8,24> id414x_3;

    (id414x_1) = (id414in_addrA.getValueAsLong());
    (id414x_2) = (id414in_addrB.getValueAsLong());
    switch(((long)((id414x_2)<(53l)))) {
      case 0l:
        id414x_3 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
      case 1l:
        id414x_3 = (id414sta_ram_store[(id414x_2)]);
        break;
      default:
        id414x_3 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id414out_doutb[(getCycle()+2)%3] = (id414x_3);
    if(((id414in_wea.getValueAsBool())&id414_inputvalid)) {
      if(((id414x_1)<(53l))) {
        (id414sta_ram_store[(id414x_1)]) = id414in_dina;
      }
      else {
        throw std::runtime_error((format_string_GRURnnKernel_3("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 414) on port A, ram depth is 53.")));
      }
    }
  }
  { // Node ID: 767 (NodeFIFO)
    const HWFloat<8,24> &id767in_input = id414out_doutb[getCycle()%3];

    id767out_output[(getCycle()+82)%83] = id767in_input;
  }
  { // Node ID: 398 (NodeMul)
    const HWFloat<8,24> &id398in_a = id387out_result[getCycle()%2];
    const HWFloat<8,24> &id398in_b = id767out_output[getCycle()%83];

    id398out_result[(getCycle()+8)%9] = (mul_float(id398in_a,id398in_b));
  }
  { // Node ID: 768 (NodeFIFO)
    const HWFloat<8,24> &id768in_input = id398out_result[getCycle()%9];

    id768out_output[(getCycle()+16)%17] = id768in_input;
  }
  { // Node ID: 399 (NodeAdd)
    const HWFloat<8,24> &id399in_a = id397out_result[getCycle()%9];
    const HWFloat<8,24> &id399in_b = id768out_output[getCycle()%17];

    id399out_result[(getCycle()+11)%12] = (add_float(id399in_a,id399in_b));
  }
  { // Node ID: 401 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id401in_sel = id769out_output[getCycle()%127];
    const HWFloat<8,24> &id401in_option0 = id400out_value;
    const HWFloat<8,24> &id401in_option1 = id399out_result[getCycle()%12];

    HWFloat<8,24> id401x_1;

    switch((id401in_sel.getValueAsLong())) {
      case 0l:
        id401x_1 = id401in_option0;
        break;
      case 1l:
        id401x_1 = id401in_option1;
        break;
      default:
        id401x_1 = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
        break;
    }
    id401out_result[(getCycle()+1)%2] = (id401x_1);
  }
  if ( (getFillLevel() >= (131l)) && (getFlushLevel() < (131l)|| !isFlushingActive() ))
  { // Node ID: 412 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id412in_output_control = id770out_output[getCycle()%128];
    const HWFloat<8,24> &id412in_data = id401out_result[getCycle()%2];

    bool id412x_1;

    (id412x_1) = ((id412in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(131l))&(isFlushingActive()))));
    if((id412x_1)) {
      writeOutput(m_vecOutput, id412in_data);
    }
  }
  { // Node ID: 420 (NodeConstantRawBits)
  }
  { // Node ID: 429 (NodeConstantRawBits)
  }
  { // Node ID: 417 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (3l)))
  { // Node ID: 418 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id418in_enable = id429out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id418in_max = id417out_value;

    HWOffsetFix<49,0,UNSIGNED> id418x_1;
    HWOffsetFix<1,0,UNSIGNED> id418x_2;
    HWOffsetFix<1,0,UNSIGNED> id418x_3;
    HWOffsetFix<49,0,UNSIGNED> id418x_4t_1e_1;

    id418out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id418st_count)));
    (id418x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id418st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id418x_2) = (gte_fixed((id418x_1),id418in_max));
    (id418x_3) = (and_fixed((id418x_2),id418in_enable));
    id418out_wrap = (id418x_3);
    if((id418in_enable.getValueAsBool())) {
      if(((id418x_3).getValueAsBool())) {
        (id418st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id418x_4t_1e_1) = (id418x_1);
        (id418st_count) = (id418x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id419out_output;

  { // Node ID: 419 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id419in_input = id418out_count;

    id419out_output = id419in_input;
  }
  if ( (getFillLevel() >= (4l)) && (getFlushLevel() < (4l)|| !isFlushingActive() ))
  { // Node ID: 421 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id421in_load = id420out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id421in_data = id419out_output;

    bool id421x_1;

    (id421x_1) = ((id421in_load.getValueAsBool())&(!(((getFlushLevel())>=(4l))&(isFlushingActive()))));
    if((id421x_1)) {
      setMappedRegValue("current_run_cycle_count", id421in_data);
    }
  }
  { // Node ID: 428 (NodeConstantRawBits)
  }
  { // Node ID: 423 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 424 (NodeCounter)
    const HWOffsetFix<1,0,UNSIGNED> &id424in_enable = id428out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id424in_max = id423out_value;

    HWOffsetFix<49,0,UNSIGNED> id424x_1;
    HWOffsetFix<1,0,UNSIGNED> id424x_2;
    HWOffsetFix<1,0,UNSIGNED> id424x_3;
    HWOffsetFix<49,0,UNSIGNED> id424x_4t_1e_1;

    id424out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id424st_count)));
    (id424x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id424st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id424x_2) = (gte_fixed((id424x_1),id424in_max));
    (id424x_3) = (and_fixed((id424x_2),id424in_enable));
    id424out_wrap = (id424x_3);
    if((id424in_enable.getValueAsBool())) {
      if(((id424x_3).getValueAsBool())) {
        (id424st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id424x_4t_1e_1) = (id424x_1);
        (id424st_count) = (id424x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 426 (NodeInputMappedReg)
  }
  { // Node ID: 590 (NodeEqInlined)
    const HWOffsetFix<48,0,UNSIGNED> &id590in_a = id424out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id590in_b = id426out_run_cycle_count;

    id590out_result[(getCycle()+1)%2] = (eq_fixed(id590in_a,id590in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 425 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id425in_start = id590out_result[getCycle()%2];

    if((id425in_start.getValueAsBool())) {
      startFlushing();
    }
  }
  { // Node ID: 1 (NodeInputMappedReg)
  }
};

};
