#include "stdsimheader.h"
#include "GRURnnKernel.h"

namespace maxcompilersim {

GRURnnKernel::GRURnnKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 131, 2, 1, 0, "",1)
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_16_0_uns_bits((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x000dl))))
, c_hw_fix_17_0_uns_bits((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00000l))))
, c_hw_fix_17_0_uns_bits_1((HWOffsetFix<17,0,UNSIGNED>(varint_u<17>(0x00001l))))
, c_hw_fix_7_0_uns_bits((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x34l))))
, c_hw_fix_7_0_uns_bits_1((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x00l))))
, c_hw_fix_7_0_uns_bits_2((HWOffsetFix<7,0,UNSIGNED>(varint_u<7>(0x01l))))
, c_hw_fix_6_0_uns_bits((HWOffsetFix<6,0,UNSIGNED>(varint_u<6>(0x01l))))
, c_hw_fix_16_0_uns_bits_1((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x0001l))))
, c_hw_flt_8_24_bits((HWFloat<8,24>(varint_u<32>(0x00000000l))))
, c_hw_fix_6_0_uns_bits_1((HWOffsetFix<6,0,UNSIGNED>(varint_u<6>(0x14l))))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_fix_6_0_uns_bits_2((HWOffsetFix<6,0,UNSIGNED>(varint_u<6>(0x00l))))
, c_hw_fix_16_0_uns_bits_2((HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(0x0000l))))
, c_hw_fix_6_0_uns_bits_3((HWOffsetFix<6,0,UNSIGNED>(varint_u<6>(0x34l))))
, c_hw_flt_8_24_bits_1((HWFloat<8,24>(varint_u<32>(0xc0a00000l))))
, c_hw_flt_8_24_bits_2((HWFloat<8,24>(varint_u<32>(0xc0180000l))))
, c_hw_flt_8_24_bits_3((HWFloat<8,24>(varint_u<32>(0xbf800000l))))
, c_hw_flt_8_24_bits_4((HWFloat<8,24>(varint_u<32>(0x3f800000l))))
, c_hw_flt_8_24_bits_5((HWFloat<8,24>(varint_u<32>(0x40180000l))))
, c_hw_flt_8_24_bits_6((HWFloat<8,24>(varint_u<32>(0x40a00000l))))
, c_hw_flt_8_24_0_03125val((HWFloat<8,24>(varint_u<32>(0x3d000000l))))
, c_hw_flt_8_24_bits_7((HWFloat<8,24>(varint_u<32>(0x3f580000l))))
, c_hw_flt_8_24_0_125val((HWFloat<8,24>(varint_u<32>(0x3e000000l))))
, c_hw_flt_8_24_bits_8((HWFloat<8,24>(varint_u<32>(0x3f200000l))))
, c_hw_flt_8_24_0_25val((HWFloat<8,24>(varint_u<32>(0x3e800000l))))
, c_hw_flt_8_24_bits_9((HWFloat<8,24>(varint_u<32>(0x3f000000l))))
, c_hw_flt_8_24_bits_10((HWFloat<8,24>(varint_u<32>(0x3ec00000l))))
, c_hw_flt_8_24_bits_11((HWFloat<8,24>(varint_u<32>(0x3e200000l))))
, c_hw_flt_8_24_bits_12((HWFloat<8,24>(varint_u<32>(0xc0e00000l))))
, c_hw_flt_8_24_bits_13((HWFloat<8,24>(varint_u<32>(0xc0400000l))))
, c_hw_flt_8_24_bits_14((HWFloat<8,24>(varint_u<32>(0xbfcccccdl))))
, c_hw_flt_8_24_bits_15((HWFloat<8,24>(varint_u<32>(0xbf4ccccdl))))
, c_hw_flt_8_24_bits_16((HWFloat<8,24>(varint_u<32>(0x3f4ccccdl))))
, c_hw_flt_8_24_bits_17((HWFloat<8,24>(varint_u<32>(0x3fcccccdl))))
, c_hw_flt_8_24_bits_18((HWFloat<8,24>(varint_u<32>(0x40400000l))))
, c_hw_flt_8_24_bits_19((HWFloat<8,24>(varint_u<32>(0x40e00000l))))
, c_hw_flt_8_24_bits_20((HWFloat<8,24>(varint_u<32>(0x3a9d4952l))))
, c_hw_flt_8_24_bits_21((HWFloat<8,24>(varint_u<32>(0x3f7dcc64l))))
, c_hw_flt_8_24_bits_22((HWFloat<8,24>(varint_u<32>(0x3d56a162l))))
, c_hw_flt_8_24_bits_23((HWFloat<8,24>(varint_u<32>(0x3f567a10l))))
, c_hw_flt_8_24_bits_24((HWFloat<8,24>(varint_u<32>(0x3ea4dd2fl))))
, c_hw_flt_8_24_bits_25((HWFloat<8,24>(varint_u<32>(0x3ef9096cl))))
, c_hw_flt_8_24_bits_26((HWFloat<8,24>(varint_u<32>(0x3f547ae1l))))
, c_hw_flt_8_24_bits_27((HWFloat<8,24>(varint_u<32>(0x3ed013a9l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
{
  { // Node ID: 3 (NodeConstantRawBits)
    id3out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 790 (NodeConstantRawBits)
    id790out_value = (c_hw_fix_16_0_uns_bits);
  }
  { // Node ID: 549 (NodeConstantRawBits)
    id549out_value = (c_hw_fix_7_0_uns_bits);
  }
  { // Node ID: 0 (NodeInputMappedReg)
    registerMappedRegister("hsize", Data(6));
  }
  { // Node ID: 548 (NodeConstantRawBits)
    id548out_value = (c_hw_fix_6_0_uns_bits);
  }
  { // Node ID: 547 (NodeConstantRawBits)
    id547out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 409 (NodeInputMappedReg)
    registerMappedRegister("io_vecOutput_force_disabled", Data(1));
  }
  { // Node ID: 546 (NodeConstantRawBits)
    id546out_value = (c_hw_fix_6_0_uns_bits);
  }
  { // Node ID: 545 (NodeConstantRawBits)
    id545out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 400 (NodeConstantRawBits)
    id400out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 544 (NodeConstantRawBits)
    id544out_value = (c_hw_fix_6_0_uns_bits);
  }
  { // Node ID: 543 (NodeConstantRawBits)
    id543out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 312 (NodeConstantRawBits)
    id312out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 542 (NodeConstantRawBits)
    id542out_value = (c_hw_fix_6_0_uns_bits);
  }
  { // Node ID: 541 (NodeConstantRawBits)
    id541out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 228 (NodeConstantRawBits)
    id228out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 540 (NodeConstantRawBits)
    id540out_value = (c_hw_fix_6_0_uns_bits_1);
  }
  { // Node ID: 539 (NodeConstantRawBits)
    id539out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 80 (NodeInputMappedReg)
    registerMappedRegister("io_Ur_force_disabled", Data(1));
  }
  { // Node ID: 83 (NodeInput)
     m_Ur =  registerInput("Ur",4,5);
  }
  { // Node ID: 538 (NodeConstantRawBits)
    id538out_value = (c_hw_fix_7_0_uns_bits);
  }
  { // Node ID: 537 (NodeConstantRawBits)
    id537out_value = (c_hw_fix_6_0_uns_bits_2);
  }
  { // Node ID: 536 (NodeConstantRawBits)
    id536out_value = (c_hw_fix_16_0_uns_bits_2);
  }
  { // Node ID: 535 (NodeConstantRawBits)
    id535out_value = (c_hw_fix_6_0_uns_bits_3);
  }
  { // Node ID: 534 (NodeConstantRawBits)
    id534out_value = (c_hw_fix_6_0_uns_bits_2);
  }
  { // Node ID: 533 (NodeConstantRawBits)
    id533out_value = (c_hw_fix_16_0_uns_bits_2);
  }
  { // Node ID: 532 (NodeConstantRawBits)
    id532out_value = (c_hw_fix_6_0_uns_bits_3);
  }
  { // Node ID: 17 (NodeInputMappedReg)
    registerMappedRegister("io_ht_force_disabled", Data(1));
  }
  { // Node ID: 20 (NodeInput)
     m_ht =  registerInput("ht",0,5);
  }
  { // Node ID: 413 (NodeRAM)
    for(int i=0;i<53;i++)
      (id413sta_ram_store[(i)]) = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
  }
  { // Node ID: 44 (NodeConstantRawBits)
    id44out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 531 (NodeConstantRawBits)
    id531out_value = (c_hw_fix_6_0_uns_bits_2);
  }
  { // Node ID: 126 (NodeConstantRawBits)
    id126out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 530 (NodeConstantRawBits)
    id530out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 529 (NodeConstantRawBits)
    id529out_value = (c_hw_fix_6_0_uns_bits_1);
  }
  { // Node ID: 90 (NodeInputMappedReg)
    registerMappedRegister("io_Wr_force_disabled", Data(1));
  }
  { // Node ID: 93 (NodeInput)
     m_Wr =  registerInput("Wr",5,5);
  }
  { // Node ID: 528 (NodeConstantRawBits)
    id528out_value = (c_hw_fix_6_0_uns_bits_1);
  }
  { // Node ID: 527 (NodeConstantRawBits)
    id527out_value = (c_hw_fix_6_0_uns_bits_2);
  }
  { // Node ID: 526 (NodeConstantRawBits)
    id526out_value = (c_hw_fix_16_0_uns_bits_2);
  }
  { // Node ID: 525 (NodeConstantRawBits)
    id525out_value = (c_hw_fix_6_0_uns_bits_1);
  }
  { // Node ID: 524 (NodeConstantRawBits)
    id524out_value = (c_hw_fix_6_0_uns_bits_2);
  }
  { // Node ID: 523 (NodeConstantRawBits)
    id523out_value = (c_hw_fix_16_0_uns_bits_2);
  }
  { // Node ID: 522 (NodeConstantRawBits)
    id522out_value = (c_hw_fix_6_0_uns_bits_1);
  }
  { // Node ID: 29 (NodeInputMappedReg)
    registerMappedRegister("io_xt_force_disabled", Data(1));
  }
  { // Node ID: 32 (NodeInput)
     m_xt =  registerInput("xt",1,5);
  }
  { // Node ID: 415 (NodeRAM)
    for(int i=0;i<21;i++)
      (id415sta_ram_store[(i)]) = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
  }
  { // Node ID: 58 (NodeConstantRawBits)
    id58out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 521 (NodeConstantRawBits)
    id521out_value = (c_hw_flt_8_24_bits_1);
  }
  { // Node ID: 520 (NodeConstantRawBits)
    id520out_value = (c_hw_flt_8_24_bits_1);
  }
  { // Node ID: 519 (NodeConstantRawBits)
    id519out_value = (c_hw_flt_8_24_bits_2);
  }
  { // Node ID: 518 (NodeConstantRawBits)
    id518out_value = (c_hw_flt_8_24_bits_2);
  }
  { // Node ID: 517 (NodeConstantRawBits)
    id517out_value = (c_hw_flt_8_24_bits_3);
  }
  { // Node ID: 516 (NodeConstantRawBits)
    id516out_value = (c_hw_flt_8_24_bits_3);
  }
  { // Node ID: 515 (NodeConstantRawBits)
    id515out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 514 (NodeConstantRawBits)
    id514out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 513 (NodeConstantRawBits)
    id513out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 512 (NodeConstantRawBits)
    id512out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 511 (NodeConstantRawBits)
    id511out_value = (c_hw_flt_8_24_bits_5);
  }
  { // Node ID: 510 (NodeConstantRawBits)
    id510out_value = (c_hw_flt_8_24_bits_5);
  }
  { // Node ID: 509 (NodeConstantRawBits)
    id509out_value = (c_hw_flt_8_24_bits_6);
  }
  { // Node ID: 219 (NodeConstantRawBits)
    id219out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 507 (NodeConstantRawBits)
    id507out_value = (c_hw_flt_8_24_bits_7);
  }
  { // Node ID: 505 (NodeConstantRawBits)
    id505out_value = (c_hw_flt_8_24_bits_8);
  }
  { // Node ID: 503 (NodeConstantRawBits)
    id503out_value = (c_hw_flt_8_24_bits_9);
  }
  { // Node ID: 501 (NodeConstantRawBits)
    id501out_value = (c_hw_flt_8_24_bits_9);
  }
  { // Node ID: 499 (NodeConstantRawBits)
    id499out_value = (c_hw_flt_8_24_bits_10);
  }
  { // Node ID: 497 (NodeConstantRawBits)
    id497out_value = (c_hw_flt_8_24_bits_11);
  }
  { // Node ID: 226 (NodeConstantRawBits)
    id226out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 496 (NodeConstantRawBits)
    id496out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 97 (NodeInputMappedReg)
    registerMappedRegister("io_Uh_force_disabled", Data(1));
  }
  { // Node ID: 100 (NodeInput)
     m_Uh =  registerInput("Uh",6,5);
  }
  { // Node ID: 495 (NodeConstantRawBits)
    id495out_value = (c_hw_fix_6_0_uns_bits_2);
  }
  { // Node ID: 139 (NodeConstantRawBits)
    id139out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 494 (NodeConstantRawBits)
    id494out_value = (c_hw_fix_6_0_uns_bits_1);
  }
  { // Node ID: 493 (NodeConstantRawBits)
    id493out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 492 (NodeConstantRawBits)
    id492out_value = (c_hw_fix_6_0_uns_bits_1);
  }
  { // Node ID: 107 (NodeInputMappedReg)
    registerMappedRegister("io_Wh_force_disabled", Data(1));
  }
  { // Node ID: 110 (NodeInput)
     m_Wh =  registerInput("Wh",7,5);
  }
  { // Node ID: 491 (NodeConstantRawBits)
    id491out_value = (c_hw_fix_6_0_uns_bits_2);
  }
  { // Node ID: 143 (NodeConstantRawBits)
    id143out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 490 (NodeConstantRawBits)
    id490out_value = (c_hw_flt_8_24_bits_12);
  }
  { // Node ID: 489 (NodeConstantRawBits)
    id489out_value = (c_hw_flt_8_24_bits_12);
  }
  { // Node ID: 488 (NodeConstantRawBits)
    id488out_value = (c_hw_flt_8_24_bits_13);
  }
  { // Node ID: 487 (NodeConstantRawBits)
    id487out_value = (c_hw_flt_8_24_bits_13);
  }
  { // Node ID: 486 (NodeConstantRawBits)
    id486out_value = (c_hw_flt_8_24_bits_14);
  }
  { // Node ID: 485 (NodeConstantRawBits)
    id485out_value = (c_hw_flt_8_24_bits_14);
  }
  { // Node ID: 484 (NodeConstantRawBits)
    id484out_value = (c_hw_flt_8_24_bits_15);
  }
  { // Node ID: 483 (NodeConstantRawBits)
    id483out_value = (c_hw_flt_8_24_bits_15);
  }
  { // Node ID: 482 (NodeConstantRawBits)
    id482out_value = (c_hw_flt_8_24_bits_16);
  }
  { // Node ID: 481 (NodeConstantRawBits)
    id481out_value = (c_hw_flt_8_24_bits_16);
  }
  { // Node ID: 480 (NodeConstantRawBits)
    id480out_value = (c_hw_flt_8_24_bits_17);
  }
  { // Node ID: 479 (NodeConstantRawBits)
    id479out_value = (c_hw_flt_8_24_bits_17);
  }
  { // Node ID: 478 (NodeConstantRawBits)
    id478out_value = (c_hw_flt_8_24_bits_18);
  }
  { // Node ID: 477 (NodeConstantRawBits)
    id477out_value = (c_hw_flt_8_24_bits_18);
  }
  { // Node ID: 476 (NodeConstantRawBits)
    id476out_value = (c_hw_flt_8_24_bits_19);
  }
  { // Node ID: 302 (NodeConstantRawBits)
    id302out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 475 (NodeConstantRawBits)
    id475out_value = (c_hw_flt_8_24_bits_20);
  }
  { // Node ID: 474 (NodeConstantRawBits)
    id474out_value = (c_hw_flt_8_24_bits_21);
  }
  { // Node ID: 473 (NodeConstantRawBits)
    id473out_value = (c_hw_flt_8_24_bits_22);
  }
  { // Node ID: 472 (NodeConstantRawBits)
    id472out_value = (c_hw_flt_8_24_bits_23);
  }
  { // Node ID: 471 (NodeConstantRawBits)
    id471out_value = (c_hw_flt_8_24_bits_24);
  }
  { // Node ID: 470 (NodeConstantRawBits)
    id470out_value = (c_hw_flt_8_24_bits_25);
  }
  { // Node ID: 469 (NodeConstantRawBits)
    id469out_value = (c_hw_flt_8_24_bits_26);
  }
  { // Node ID: 468 (NodeConstantRawBits)
    id468out_value = (c_hw_flt_8_24_bits_24);
  }
  { // Node ID: 467 (NodeConstantRawBits)
    id467out_value = (c_hw_flt_8_24_bits_27);
  }
  { // Node ID: 466 (NodeConstantRawBits)
    id466out_value = (c_hw_flt_8_24_bits_22);
  }
  { // Node ID: 465 (NodeConstantRawBits)
    id465out_value = (c_hw_flt_8_24_bits_23);
  }
  { // Node ID: 464 (NodeConstantRawBits)
    id464out_value = (c_hw_flt_8_24_bits_20);
  }
  { // Node ID: 463 (NodeConstantRawBits)
    id463out_value = (c_hw_flt_8_24_bits_21);
  }
  { // Node ID: 310 (NodeConstantRawBits)
    id310out_value = (c_hw_flt_8_24_bits_3);
  }
  { // Node ID: 462 (NodeConstantRawBits)
    id462out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 461 (NodeConstantRawBits)
    id461out_value = (c_hw_fix_6_0_uns_bits);
  }
  { // Node ID: 460 (NodeConstantRawBits)
    id460out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 386 (NodeConstantRawBits)
    id386out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 459 (NodeConstantRawBits)
    id459out_value = (c_hw_fix_6_0_uns_bits_1);
  }
  { // Node ID: 458 (NodeConstantRawBits)
    id458out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 63 (NodeInputMappedReg)
    registerMappedRegister("io_Uz_force_disabled", Data(1));
  }
  { // Node ID: 66 (NodeInput)
     m_Uz =  registerInput("Uz",2,5);
  }
  { // Node ID: 457 (NodeConstantRawBits)
    id457out_value = (c_hw_fix_6_0_uns_bits_2);
  }
  { // Node ID: 113 (NodeConstantRawBits)
    id113out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 456 (NodeConstantRawBits)
    id456out_value = (c_hw_fix_16_0_uns_bits_1);
  }
  { // Node ID: 455 (NodeConstantRawBits)
    id455out_value = (c_hw_fix_6_0_uns_bits_1);
  }
  { // Node ID: 73 (NodeInputMappedReg)
    registerMappedRegister("io_Wz_force_disabled", Data(1));
  }
  { // Node ID: 76 (NodeInput)
     m_Wz =  registerInput("Wz",3,5);
  }
  { // Node ID: 454 (NodeConstantRawBits)
    id454out_value = (c_hw_flt_8_24_bits_1);
  }
  { // Node ID: 453 (NodeConstantRawBits)
    id453out_value = (c_hw_flt_8_24_bits_1);
  }
  { // Node ID: 452 (NodeConstantRawBits)
    id452out_value = (c_hw_flt_8_24_bits_2);
  }
  { // Node ID: 451 (NodeConstantRawBits)
    id451out_value = (c_hw_flt_8_24_bits_2);
  }
  { // Node ID: 450 (NodeConstantRawBits)
    id450out_value = (c_hw_flt_8_24_bits_3);
  }
  { // Node ID: 449 (NodeConstantRawBits)
    id449out_value = (c_hw_flt_8_24_bits_3);
  }
  { // Node ID: 448 (NodeConstantRawBits)
    id448out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 447 (NodeConstantRawBits)
    id447out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 446 (NodeConstantRawBits)
    id446out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 445 (NodeConstantRawBits)
    id445out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 444 (NodeConstantRawBits)
    id444out_value = (c_hw_flt_8_24_bits_5);
  }
  { // Node ID: 443 (NodeConstantRawBits)
    id443out_value = (c_hw_flt_8_24_bits_5);
  }
  { // Node ID: 442 (NodeConstantRawBits)
    id442out_value = (c_hw_flt_8_24_bits_6);
  }
  { // Node ID: 377 (NodeConstantRawBits)
    id377out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 440 (NodeConstantRawBits)
    id440out_value = (c_hw_flt_8_24_bits_7);
  }
  { // Node ID: 438 (NodeConstantRawBits)
    id438out_value = (c_hw_flt_8_24_bits_8);
  }
  { // Node ID: 436 (NodeConstantRawBits)
    id436out_value = (c_hw_flt_8_24_bits_9);
  }
  { // Node ID: 434 (NodeConstantRawBits)
    id434out_value = (c_hw_flt_8_24_bits_9);
  }
  { // Node ID: 432 (NodeConstantRawBits)
    id432out_value = (c_hw_flt_8_24_bits_10);
  }
  { // Node ID: 430 (NodeConstantRawBits)
    id430out_value = (c_hw_flt_8_24_bits_11);
  }
  { // Node ID: 384 (NodeConstantRawBits)
    id384out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 414 (NodeRAM)
    for(int i=0;i<53;i++)
      (id414sta_ram_store[(i)]) = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
  }
  { // Node ID: 412 (NodeOutput)
    m_vecOutput = registerOutput("vecOutput",0 );
  }
  { // Node ID: 420 (NodeConstantRawBits)
    id420out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 429 (NodeConstantRawBits)
    id429out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 417 (NodeConstantRawBits)
    id417out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 421 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48), true);
  }
  { // Node ID: 428 (NodeConstantRawBits)
    id428out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 423 (NodeConstantRawBits)
    id423out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 426 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
  { // Node ID: 1 (NodeInputMappedReg)
    registerMappedRegister("n", Data(5));
  }
}

void GRURnnKernel::ramInitialise() {
  { // Node ID: 413 (NodeRAM)
    for(int i=0;i<53;i++)
      (id413sta_ram_store[(i)]) = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
  }
  { // Node ID: 415 (NodeRAM)
    for(int i=0;i<21;i++)
      (id415sta_ram_store[(i)]) = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
  }
  { // Node ID: 414 (NodeRAM)
    for(int i=0;i<53;i++)
      (id414sta_ram_store[(i)]) = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
  }
}

void GRURnnKernel::resetComputation() {
  resetComputationAfterFlush();
}

void GRURnnKernel::resetComputationAfterFlush() {
  { // Node ID: 8 (NodeCounter)

    (id8st_count) = (c_hw_fix_17_0_uns_bits);
  }
  { // Node ID: 7 (NodeCounter)

    (id7st_count) = (c_hw_fix_7_0_uns_bits_1);
  }
  { // Node ID: 612 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id612out_output[i] = (HWOffsetFix<6,0,UNSIGNED>(varint_u<6>(m_undefined_value.get_bits(6))));
    }
  }
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_hsize = getMappedRegValue<HWOffsetFix<6,0,UNSIGNED> >("hsize");
  }
  { // Node ID: 613 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id613out_output[i] = (HWOffsetFix<16,0,UNSIGNED>(varint_u<16>(m_undefined_value.get_bits(16))));
    }
  }
  { // Node ID: 409 (NodeInputMappedReg)
    id409out_io_vecOutput_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_vecOutput_force_disabled");
  }
  { // Node ID: 770 (NodeFIFO)

    for(int i=0; i<128; i++)
    {
      id770out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 769 (NodeFIFO)

    for(int i=0; i<127; i++)
    {
      id769out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 721 (NodeFIFO)

    for(int i=0; i<107; i++)
    {
      id721out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 674 (NodeFIFO)

    for(int i=0; i<60; i++)
    {
      id674out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 771 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id771out_output[i] = (HWOffsetFix<6,0,UNSIGNED>(varint_u<6>(m_undefined_value.get_bits(6))));
    }
  }
  { // Node ID: 772 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id772out_output[i] = (HWOffsetFix<6,0,UNSIGNED>(varint_u<6>(m_undefined_value.get_bits(6))));
    }
  }
  { // Node ID: 773 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id773out_output[i] = (HWOffsetFix<6,0,UNSIGNED>(varint_u<6>(m_undefined_value.get_bits(6))));
    }
  }
  { // Node ID: 774 (NodeFIFO)

    for(int i=0; i<20; i++)
    {
      id774out_output[i] = (HWOffsetFix<6,0,UNSIGNED>(varint_u<6>(m_undefined_value.get_bits(6))));
    }
  }
  { // Node ID: 648 (NodeFIFO)

    for(int i=0; i<13; i++)
    {
      id648out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 80 (NodeInputMappedReg)
    id80out_io_Ur_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_Ur_force_disabled");
  }
  { // Node ID: 622 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id622out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 83 (NodeInput)

    (id83st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id83st_last_read_value) = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
  }
  { // Node ID: 5 (NodeCounter)

    (id5st_count) = (c_hw_fix_7_0_uns_bits_1);
  }
  { // Node ID: 624 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id624out_output[i] = (HWOffsetFix<6,0,UNSIGNED>(varint_u<6>(m_undefined_value.get_bits(6))));
    }
  }
  { // Node ID: 631 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id631out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 17 (NodeInputMappedReg)
    id17out_io_ht_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_ht_force_disabled");
  }
  { // Node ID: 20 (NodeInput)

    (id20st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id20st_last_read_value) = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
  }
  { // Node ID: 629 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id629out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 632 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id632out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 634 (NodeFIFO)

    for(int i=0; i<12; i++)
    {
      id634out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 90 (NodeInputMappedReg)
    id90out_io_Wr_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_Wr_force_disabled");
  }
  { // Node ID: 637 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id637out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 93 (NodeInput)

    (id93st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id93st_last_read_value) = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
  }
  { // Node ID: 646 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id646out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 29 (NodeInputMappedReg)
    id29out_io_xt_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_xt_force_disabled");
  }
  { // Node ID: 32 (NodeInput)

    (id32st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id32st_last_read_value) = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
  }
  { // Node ID: 645 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id645out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 647 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id647out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 663 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id663out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 777 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id777out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 778 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id778out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 779 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id779out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 780 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id780out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 673 (NodeFIFO)

    for(int i=0; i<12; i++)
    {
      id673out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 672 (NodeFIFO)

    for(int i=0; i<10; i++)
    {
      id672out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 670 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id670out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 668 (NodeFIFO)

    for(int i=0; i<8; i++)
    {
      id668out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 666 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id666out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 664 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id664out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 662 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id662out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 97 (NodeInputMappedReg)
    id97out_io_Uh_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_Uh_force_disabled");
  }
  { // Node ID: 676 (NodeFIFO)

    for(int i=0; i<37; i++)
    {
      id676out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 100 (NodeInput)

    (id100st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id100st_last_read_value) = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
  }
  { // Node ID: 677 (NodeFIFO)

    for(int i=0; i<32; i++)
    {
      id677out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 680 (NodeFIFO)

    for(int i=0; i<21; i++)
    {
      id680out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 679 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id679out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 689 (NodeFIFO)

    for(int i=0; i<33; i++)
    {
      id689out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 690 (NodeFIFO)

    for(int i=0; i<13; i++)
    {
      id690out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 107 (NodeInputMappedReg)
    id107out_io_Wh_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_Wh_force_disabled");
  }
  { // Node ID: 685 (NodeFIFO)

    for(int i=0; i<36; i++)
    {
      id685out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 110 (NodeInput)

    (id110st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id110st_last_read_value) = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
  }
  { // Node ID: 686 (NodeFIFO)

    for(int i=0; i<32; i++)
    {
      id686out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 688 (NodeFIFO)

    for(int i=0; i<21; i++)
    {
      id688out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 691 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id691out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 708 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id708out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 781 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id781out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 782 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id782out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 783 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id783out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 784 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id784out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 785 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id785out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 720 (NodeFIFO)

    for(int i=0; i<11; i++)
    {
      id720out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 719 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id719out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 717 (NodeFIFO)

    for(int i=0; i<8; i++)
    {
      id717out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 715 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id715out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 713 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id713out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 711 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id711out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 709 (NodeFIFO)

    for(int i=0; i<4; i++)
    {
      id709out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 707 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id707out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 761 (NodeFIFO)

    for(int i=0; i<91; i++)
    {
      id761out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 735 (NodeFIFO)

    for(int i=0; i<44; i++)
    {
      id735out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 63 (NodeInputMappedReg)
    id63out_io_Uz_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_Uz_force_disabled");
  }
  { // Node ID: 726 (NodeFIFO)

    for(int i=0; i<37; i++)
    {
      id726out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 66 (NodeInput)

    (id66st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id66st_last_read_value) = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
  }
  { // Node ID: 730 (NodeFIFO)

    for(int i=0; i<12; i++)
    {
      id730out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 729 (NodeFIFO)

    for(int i=0; i<32; i++)
    {
      id729out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 73 (NodeInputMappedReg)
    id73out_io_Wz_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_Wz_force_disabled");
  }
  { // Node ID: 733 (NodeFIFO)

    for(int i=0; i<36; i++)
    {
      id733out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 76 (NodeInput)

    (id76st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id76st_last_read_value) = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
  }
  { // Node ID: 750 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id750out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 786 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id786out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 787 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id787out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 788 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id788out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 789 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id789out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 760 (NodeFIFO)

    for(int i=0; i<12; i++)
    {
      id760out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 759 (NodeFIFO)

    for(int i=0; i<10; i++)
    {
      id759out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 757 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id757out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 755 (NodeFIFO)

    for(int i=0; i<8; i++)
    {
      id755out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 753 (NodeFIFO)

    for(int i=0; i<7; i++)
    {
      id753out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 751 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id751out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 749 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id749out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 762 (NodeFIFO)

    for(int i=0; i<6; i++)
    {
      id762out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 776 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id776out_output[i] = (HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(m_undefined_value.get_bits(1))));
    }
  }
  { // Node ID: 775 (NodeFIFO)

    for(int i=0; i<10; i++)
    {
      id775out_output[i] = (HWOffsetFix<6,0,UNSIGNED>(varint_u<6>(m_undefined_value.get_bits(6))));
    }
  }
  { // Node ID: 767 (NodeFIFO)

    for(int i=0; i<83; i++)
    {
      id767out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 768 (NodeFIFO)

    for(int i=0; i<17; i++)
    {
      id768out_output[i] = (HWFloat<8,24>(varint_u<32>(m_undefined_value.get_bits(32))));
    }
  }
  { // Node ID: 418 (NodeCounter)

    (id418st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 424 (NodeCounter)

    (id424st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 426 (NodeInputMappedReg)
    id426out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
  { // Node ID: 1 (NodeInputMappedReg)
    id1out_n = getMappedRegValue<HWOffsetFix<5,0,UNSIGNED> >("n");
  }
}

void GRURnnKernel::updateState() {
  { // Node ID: 0 (NodeInputMappedReg)
    id0out_hsize = getMappedRegValue<HWOffsetFix<6,0,UNSIGNED> >("hsize");
  }
  { // Node ID: 409 (NodeInputMappedReg)
    id409out_io_vecOutput_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_vecOutput_force_disabled");
  }
  { // Node ID: 80 (NodeInputMappedReg)
    id80out_io_Ur_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_Ur_force_disabled");
  }
  { // Node ID: 17 (NodeInputMappedReg)
    id17out_io_ht_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_ht_force_disabled");
  }
  { // Node ID: 90 (NodeInputMappedReg)
    id90out_io_Wr_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_Wr_force_disabled");
  }
  { // Node ID: 29 (NodeInputMappedReg)
    id29out_io_xt_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_xt_force_disabled");
  }
  { // Node ID: 97 (NodeInputMappedReg)
    id97out_io_Uh_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_Uh_force_disabled");
  }
  { // Node ID: 107 (NodeInputMappedReg)
    id107out_io_Wh_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_Wh_force_disabled");
  }
  { // Node ID: 63 (NodeInputMappedReg)
    id63out_io_Uz_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_Uz_force_disabled");
  }
  { // Node ID: 73 (NodeInputMappedReg)
    id73out_io_Wz_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_Wz_force_disabled");
  }
  { // Node ID: 426 (NodeInputMappedReg)
    id426out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
  { // Node ID: 1 (NodeInputMappedReg)
    id1out_n = getMappedRegValue<HWOffsetFix<5,0,UNSIGNED> >("n");
  }
}

void GRURnnKernel::preExecute() {
  { // Node ID: 83 (NodeInput)
    if(((needsToReadInput(m_Ur))&(((getFlushLevel())<((8l)+(5)))|(!(isFlushingActive()))))) {
      (id83st_last_read_value) = (readInput<HWFloat<8,24> >(m_Ur));
    }
    id83out_data = (id83st_last_read_value);
  }
  { // Node ID: 20 (NodeInput)
    if(((needsToReadInput(m_ht))&(((getFlushLevel())<((4l)+(5)))|(!(isFlushingActive()))))) {
      (id20st_last_read_value) = (readInput<HWFloat<8,24> >(m_ht));
    }
    id20out_data = (id20st_last_read_value);
  }
  { // Node ID: 93 (NodeInput)
    if(((needsToReadInput(m_Wr))&(((getFlushLevel())<((8l)+(5)))|(!(isFlushingActive()))))) {
      (id93st_last_read_value) = (readInput<HWFloat<8,24> >(m_Wr));
    }
    id93out_data = (id93st_last_read_value);
  }
  { // Node ID: 32 (NodeInput)
    if(((needsToReadInput(m_xt))&(((getFlushLevel())<((4l)+(5)))|(!(isFlushingActive()))))) {
      (id32st_last_read_value) = (readInput<HWFloat<8,24> >(m_xt));
    }
    id32out_data = (id32st_last_read_value);
  }
  { // Node ID: 100 (NodeInput)
    if(((needsToReadInput(m_Uh))&(((getFlushLevel())<((39l)+(5)))|(!(isFlushingActive()))))) {
      (id100st_last_read_value) = (readInput<HWFloat<8,24> >(m_Uh));
    }
    id100out_data = (id100st_last_read_value);
  }
  { // Node ID: 110 (NodeInput)
    if(((needsToReadInput(m_Wh))&(((getFlushLevel())<((39l)+(5)))|(!(isFlushingActive()))))) {
      (id110st_last_read_value) = (readInput<HWFloat<8,24> >(m_Wh));
    }
    id110out_data = (id110st_last_read_value);
  }
  { // Node ID: 66 (NodeInput)
    if(((needsToReadInput(m_Uz))&(((getFlushLevel())<((39l)+(5)))|(!(isFlushingActive()))))) {
      (id66st_last_read_value) = (readInput<HWFloat<8,24> >(m_Uz));
    }
    id66out_data = (id66st_last_read_value);
  }
  { // Node ID: 76 (NodeInput)
    if(((needsToReadInput(m_Wz))&(((getFlushLevel())<((39l)+(5)))|(!(isFlushingActive()))))) {
      (id76st_last_read_value) = (readInput<HWFloat<8,24> >(m_Wz));
    }
    id76out_data = (id76st_last_read_value);
  }
}

void GRURnnKernel::runComputationCycle() {
  if (m_mappedElementsChanged) {
    m_mappedElementsChanged = false;
    updateState();
    std::cout << "GRURnnKernel: Mapped Elements Changed: Reloaded" << std::endl;
  }
  preExecute();
  execute0();
}

int GRURnnKernel::getFlushLevelStart() {
  return ((1l)+(3l));
}

}
