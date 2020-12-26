#ifndef GRURNNKERNEL_H_
#define GRURNNKERNEL_H_

// #include "KernelManagerBlockSync.h"


namespace maxcompilersim {

class GRURnnKernel : public KernelManagerBlockSync {
public:
  GRURnnKernel(const std::string &instance_name);

protected:
  virtual void runComputationCycle();
  virtual void ramInitialise();
  virtual void resetComputation();
  virtual void resetComputationAfterFlush();
          void updateState();
          void preExecute();
  virtual int  getFlushLevelStart();

private:
  t_port_number m_Ur;
  t_port_number m_ht;
  t_port_number m_Wr;
  t_port_number m_xt;
  t_port_number m_Uh;
  t_port_number m_Wh;
  t_port_number m_Uz;
  t_port_number m_Wz;
  t_port_number m_vecOutput;
  HWOffsetFix<1,0,UNSIGNED> id3out_value;

  HWOffsetFix<16,0,UNSIGNED> id790out_value;

  HWOffsetFix<16,0,UNSIGNED> id8out_count;
  HWOffsetFix<1,0,UNSIGNED> id8out_wrap;

  HWOffsetFix<17,0,UNSIGNED> id8st_count;

  HWOffsetFix<7,0,UNSIGNED> id549out_value;

  HWOffsetFix<6,0,UNSIGNED> id7out_count;
  HWOffsetFix<1,0,UNSIGNED> id7out_wrap;

  HWOffsetFix<7,0,UNSIGNED> id7st_count;

  HWOffsetFix<6,0,UNSIGNED> id612out_output[2];

  HWOffsetFix<6,0,UNSIGNED> id0out_hsize;

  HWOffsetFix<6,0,UNSIGNED> id548out_value;

  HWOffsetFix<6,0,UNSIGNED> id403out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id550out_result[2];

  HWOffsetFix<16,0,UNSIGNED> id613out_output[2];

  HWOffsetFix<16,0,UNSIGNED> id547out_value;

  HWOffsetFix<16,0,UNSIGNED> id406out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id551out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id408out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id409out_io_vecOutput_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id770out_output[128];

  HWOffsetFix<6,0,UNSIGNED> id546out_value;

  HWOffsetFix<6,0,UNSIGNED> id389out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id552out_result[2];

  HWOffsetFix<16,0,UNSIGNED> id545out_value;

  HWOffsetFix<16,0,UNSIGNED> id392out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id553out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id394out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id769out_output[127];

  HWFloat<8,24> id400out_value;

  HWOffsetFix<6,0,UNSIGNED> id544out_value;

  HWOffsetFix<6,0,UNSIGNED> id231out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id554out_result[2];

  HWOffsetFix<16,0,UNSIGNED> id543out_value;

  HWOffsetFix<16,0,UNSIGNED> id234out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id555out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id236out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id721out_output[107];

  HWFloat<8,24> id312out_value;

  HWOffsetFix<6,0,UNSIGNED> id542out_value;

  HWOffsetFix<6,0,UNSIGNED> id157out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id556out_result[2];

  HWOffsetFix<16,0,UNSIGNED> id541out_value;

  HWOffsetFix<16,0,UNSIGNED> id160out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id557out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id162out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id674out_output[60];

  HWFloat<8,24> id228out_value;

  HWOffsetFix<6,0,UNSIGNED> id771out_output[2];

  HWOffsetFix<6,0,UNSIGNED> id772out_output[7];

  HWOffsetFix<6,0,UNSIGNED> id773out_output[3];

  HWOffsetFix<6,0,UNSIGNED> id774out_output[20];

  HWOffsetFix<6,0,UNSIGNED> id540out_value;

  HWOffsetFix<1,0,UNSIGNED> id558out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id648out_output[13];

  HWOffsetFix<16,0,UNSIGNED> id539out_value;

  HWOffsetFix<16,0,UNSIGNED> id78out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id559out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id80out_io_Ur_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id622out_output[6];

  HWFloat<8,24> id83out_data;

  HWOffsetFix<1,0,UNSIGNED> id83st_read_next_cycle;
  HWFloat<8,24> id83st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id560out_result[2];

  HWOffsetFix<7,0,UNSIGNED> id538out_value;

  HWOffsetFix<6,0,UNSIGNED> id5out_count;
  HWOffsetFix<1,0,UNSIGNED> id5out_wrap;

  HWOffsetFix<7,0,UNSIGNED> id5st_count;

  HWOffsetFix<6,0,UNSIGNED> id624out_output[2];

  HWOffsetFix<6,0,UNSIGNED> id537out_value;

  HWOffsetFix<1,0,UNSIGNED> id561out_result[2];

  HWOffsetFix<16,0,UNSIGNED> id536out_value;

  HWOffsetFix<1,0,UNSIGNED> id562out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id38out_result[2];

  HWOffsetFix<6,0,UNSIGNED> id535out_value;

  HWOffsetFix<1,0,UNSIGNED> id563out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id41out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id631out_output[7];

  HWOffsetFix<6,0,UNSIGNED> id534out_value;

  HWOffsetFix<1,0,UNSIGNED> id564out_result[2];

  HWOffsetFix<16,0,UNSIGNED> id533out_value;

  HWOffsetFix<1,0,UNSIGNED> id565out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id13out_result[2];

  HWOffsetFix<6,0,UNSIGNED> id532out_value;

  HWOffsetFix<1,0,UNSIGNED> id566out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id16out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id17out_io_ht_force_disabled;

  HWFloat<8,24> id20out_data;

  HWOffsetFix<1,0,UNSIGNED> id20st_read_next_cycle;
  HWFloat<8,24> id20st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id629out_output[6];

  HWFloat<8,24> id413out_doutb[3];

  HWFloat<8,24> id413sta_ram_store[53];

  std::string format_string_GRURnnKernel_1 (const char* _format_arg_format_string);
  HWFloat<8,24> id632out_output[3];

  HWFloat<8,24> id42out_result[2];

  HWFloat<8,24> id44out_value;

  HWFloat<8,24> id45out_result[2];

  HWFloat<8,24> id134out_result[9];

  HWFloat<8,24> id634out_output[12];

  HWOffsetFix<6,0,UNSIGNED> id531out_value;

  HWOffsetFix<1,0,UNSIGNED> id567out_result[2];

  HWFloat<8,24> id126out_value;

  HWFloat<8,24> id127out_result[2];

  HWFloat<8,24> id135out_result[12];

  HWOffsetFix<16,0,UNSIGNED> id530out_value;

  HWOffsetFix<16,0,UNSIGNED> id85out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id568out_result[2];

  HWOffsetFix<6,0,UNSIGNED> id529out_value;

  HWOffsetFix<1,0,UNSIGNED> id569out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id89out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id90out_io_Wr_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id637out_output[5];

  HWFloat<8,24> id93out_data;

  HWOffsetFix<1,0,UNSIGNED> id93st_read_next_cycle;
  HWFloat<8,24> id93st_last_read_value;

  HWOffsetFix<6,0,UNSIGNED> id528out_value;

  HWOffsetFix<1,0,UNSIGNED> id570out_result[2];

  HWOffsetFix<6,0,UNSIGNED> id527out_value;

  HWOffsetFix<1,0,UNSIGNED> id571out_result[2];

  HWOffsetFix<16,0,UNSIGNED> id526out_value;

  HWOffsetFix<1,0,UNSIGNED> id572out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id50out_result[2];

  HWOffsetFix<6,0,UNSIGNED> id525out_value;

  HWOffsetFix<1,0,UNSIGNED> id573out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id53out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id646out_output[7];

  HWOffsetFix<6,0,UNSIGNED> id524out_value;

  HWOffsetFix<1,0,UNSIGNED> id574out_result[2];

  HWOffsetFix<16,0,UNSIGNED> id523out_value;

  HWOffsetFix<1,0,UNSIGNED> id575out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id25out_result[2];

  HWOffsetFix<6,0,UNSIGNED> id522out_value;

  HWOffsetFix<1,0,UNSIGNED> id576out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id28out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id29out_io_xt_force_disabled;

  HWFloat<8,24> id32out_data;

  HWOffsetFix<1,0,UNSIGNED> id32st_read_next_cycle;
  HWFloat<8,24> id32st_last_read_value;

  HWOffsetFix<1,0,UNSIGNED> id645out_output[6];

  HWFloat<8,24> id415out_doutb[3];

  HWFloat<8,24> id415sta_ram_store[21];

  std::string format_string_GRURnnKernel_2 (const char* _format_arg_format_string);
  HWFloat<8,24> id647out_output[3];

  HWFloat<8,24> id55out_result[2];

  HWFloat<8,24> id58out_value;

  HWFloat<8,24> id59out_result[2];

  HWFloat<8,24> id131out_result[9];

  HWFloat<8,24> id132out_result[12];

  HWFloat<8,24> id133out_result[12];

  HWFloat<8,24> id136out_result[2];

  HWFloat<8,24> id663out_output[2];

  HWFloat<8,24> id777out_output[2];

  HWFloat<8,24> id778out_output[2];

  HWFloat<8,24> id779out_output[2];

  HWFloat<8,24> id780out_output[2];

  HWFloat<8,24> id521out_value;

  HWOffsetFix<1,0,UNSIGNED> id164out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id673out_output[12];

  HWFloat<8,24> id520out_value;

  HWOffsetFix<1,0,UNSIGNED> id166out_result[3];

  HWFloat<8,24> id519out_value;

  HWOffsetFix<1,0,UNSIGNED> id168out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id169out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id672out_output[10];

  HWFloat<8,24> id518out_value;

  HWOffsetFix<1,0,UNSIGNED> id175out_result[3];

  HWFloat<8,24> id517out_value;

  HWOffsetFix<1,0,UNSIGNED> id177out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id178out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id670out_output[9];

  HWFloat<8,24> id516out_value;

  HWOffsetFix<1,0,UNSIGNED> id184out_result[3];

  HWFloat<8,24> id515out_value;

  HWOffsetFix<1,0,UNSIGNED> id186out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id187out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id668out_output[8];

  HWFloat<8,24> id514out_value;

  HWOffsetFix<1,0,UNSIGNED> id193out_result[3];

  HWFloat<8,24> id513out_value;

  HWOffsetFix<1,0,UNSIGNED> id195out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id196out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id666out_output[7];

  HWFloat<8,24> id512out_value;

  HWOffsetFix<1,0,UNSIGNED> id202out_result[3];

  HWFloat<8,24> id511out_value;

  HWOffsetFix<1,0,UNSIGNED> id204out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id205out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id664out_output[6];

  HWFloat<8,24> id510out_value;

  HWOffsetFix<1,0,UNSIGNED> id211out_result[3];

  HWFloat<8,24> id509out_value;

  HWOffsetFix<1,0,UNSIGNED> id213out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id214out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id662out_output[5];

  HWFloat<8,24> id219out_value;

  HWFloat<8,24> id591out_floatOut[2];

  HWFloat<8,24> id507out_value;

  HWFloat<8,24> id218out_result[12];

  HWFloat<8,24> id220out_result[2];

  HWFloat<8,24> id592out_floatOut[2];

  HWFloat<8,24> id505out_value;

  HWFloat<8,24> id209out_result[12];

  HWFloat<8,24> id221out_result[2];

  HWFloat<8,24> id593out_floatOut[2];

  HWFloat<8,24> id503out_value;

  HWFloat<8,24> id200out_result[12];

  HWFloat<8,24> id222out_result[2];

  HWFloat<8,24> id594out_floatOut[2];

  HWFloat<8,24> id501out_value;

  HWFloat<8,24> id191out_result[12];

  HWFloat<8,24> id223out_result[2];

  HWFloat<8,24> id595out_floatOut[2];

  HWFloat<8,24> id499out_value;

  HWFloat<8,24> id182out_result[12];

  HWFloat<8,24> id224out_result[2];

  HWFloat<8,24> id596out_floatOut[2];

  HWFloat<8,24> id497out_value;

  HWFloat<8,24> id173out_result[12];

  HWFloat<8,24> id225out_result[2];

  HWFloat<8,24> id226out_value;

  HWFloat<8,24> id227out_result[2];

  HWFloat<8,24> id229out_result[2];

  HWOffsetFix<16,0,UNSIGNED> id496out_value;

  HWOffsetFix<16,0,UNSIGNED> id95out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id577out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id97out_io_Uh_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id676out_output[37];

  HWFloat<8,24> id100out_data;

  HWOffsetFix<1,0,UNSIGNED> id100st_read_next_cycle;
  HWFloat<8,24> id100st_last_read_value;

  HWFloat<8,24> id677out_output[32];

  HWFloat<8,24> id145out_result[9];

  HWOffsetFix<6,0,UNSIGNED> id495out_value;

  HWOffsetFix<1,0,UNSIGNED> id578out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id680out_output[21];

  HWFloat<8,24> id139out_value;

  HWFloat<8,24> id140out_result[2];

  HWFloat<8,24> id146out_result[12];

  HWFloat<8,24> id679out_output[2];

  HWFloat<8,24> id237out_result[9];

  HWOffsetFix<6,0,UNSIGNED> id494out_value;

  HWOffsetFix<1,0,UNSIGNED> id579out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id689out_output[33];

  HWFloat<8,24> id690out_output[13];

  HWOffsetFix<16,0,UNSIGNED> id493out_value;

  HWOffsetFix<16,0,UNSIGNED> id102out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id580out_result[2];

  HWOffsetFix<6,0,UNSIGNED> id492out_value;

  HWOffsetFix<1,0,UNSIGNED> id581out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id106out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id107out_io_Wh_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id685out_output[36];

  HWFloat<8,24> id110out_data;

  HWOffsetFix<1,0,UNSIGNED> id110st_read_next_cycle;
  HWFloat<8,24> id110st_last_read_value;

  HWFloat<8,24> id686out_output[32];

  HWFloat<8,24> id149out_result[9];

  HWOffsetFix<6,0,UNSIGNED> id491out_value;

  HWOffsetFix<1,0,UNSIGNED> id582out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id688out_output[21];

  HWFloat<8,24> id143out_value;

  HWFloat<8,24> id144out_result[2];

  HWFloat<8,24> id150out_result[12];

  HWFloat<8,24> id151out_result[2];

  HWFloat<8,24> id691out_output[9];

  HWFloat<8,24> id238out_result[12];

  HWFloat<8,24> id708out_output[2];

  HWFloat<8,24> id781out_output[2];

  HWFloat<8,24> id782out_output[3];

  HWFloat<8,24> id783out_output[2];

  HWFloat<8,24> id784out_output[2];

  HWFloat<8,24> id785out_output[9];

  HWFloat<8,24> id490out_value;

  HWOffsetFix<1,0,UNSIGNED> id240out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id720out_output[11];

  HWFloat<8,24> id489out_value;

  HWOffsetFix<1,0,UNSIGNED> id242out_result[3];

  HWFloat<8,24> id488out_value;

  HWOffsetFix<1,0,UNSIGNED> id244out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id245out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id719out_output[9];

  HWFloat<8,24> id487out_value;

  HWOffsetFix<1,0,UNSIGNED> id251out_result[3];

  HWFloat<8,24> id486out_value;

  HWOffsetFix<1,0,UNSIGNED> id253out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id254out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id717out_output[8];

  HWFloat<8,24> id485out_value;

  HWOffsetFix<1,0,UNSIGNED> id260out_result[3];

  HWFloat<8,24> id484out_value;

  HWOffsetFix<1,0,UNSIGNED> id262out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id263out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id715out_output[7];

  HWFloat<8,24> id483out_value;

  HWOffsetFix<1,0,UNSIGNED> id269out_result[3];

  HWFloat<8,24> id482out_value;

  HWOffsetFix<1,0,UNSIGNED> id271out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id272out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id713out_output[6];

  HWFloat<8,24> id481out_value;

  HWOffsetFix<1,0,UNSIGNED> id276out_result[3];

  HWFloat<8,24> id480out_value;

  HWOffsetFix<1,0,UNSIGNED> id278out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id279out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id711out_output[5];

  HWFloat<8,24> id479out_value;

  HWOffsetFix<1,0,UNSIGNED> id285out_result[3];

  HWFloat<8,24> id478out_value;

  HWOffsetFix<1,0,UNSIGNED> id287out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id288out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id709out_output[4];

  HWFloat<8,24> id477out_value;

  HWOffsetFix<1,0,UNSIGNED> id294out_result[3];

  HWFloat<8,24> id476out_value;

  HWOffsetFix<1,0,UNSIGNED> id296out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id297out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id707out_output[3];

  HWFloat<8,24> id302out_value;

  HWFloat<8,24> id475out_value;

  HWFloat<8,24> id299out_result[9];

  HWFloat<8,24> id474out_value;

  HWFloat<8,24> id301out_result[12];

  HWFloat<8,24> id303out_result[2];

  HWFloat<8,24> id473out_value;

  HWFloat<8,24> id290out_result[9];

  HWFloat<8,24> id472out_value;

  HWFloat<8,24> id292out_result[12];

  HWFloat<8,24> id304out_result[2];

  HWFloat<8,24> id471out_value;

  HWFloat<8,24> id281out_result[9];

  HWFloat<8,24> id470out_value;

  HWFloat<8,24> id283out_result[12];

  HWFloat<8,24> id305out_result[2];

  HWFloat<8,24> id469out_value;

  HWFloat<8,24> id274out_result[9];

  HWFloat<8,24> id306out_result[2];

  HWFloat<8,24> id468out_value;

  HWFloat<8,24> id265out_result[9];

  HWFloat<8,24> id467out_value;

  HWFloat<8,24> id267out_result[12];

  HWFloat<8,24> id307out_result[2];

  HWFloat<8,24> id466out_value;

  HWFloat<8,24> id256out_result[9];

  HWFloat<8,24> id465out_value;

  HWFloat<8,24> id258out_result[12];

  HWFloat<8,24> id308out_result[2];

  HWFloat<8,24> id464out_value;

  HWFloat<8,24> id247out_result[9];

  HWFloat<8,24> id463out_value;

  HWFloat<8,24> id249out_result[12];

  HWFloat<8,24> id309out_result[2];

  HWFloat<8,24> id310out_value;

  HWFloat<8,24> id311out_result[2];

  HWFloat<8,24> id313out_result[2];

  HWFloat<8,24> id462out_value;

  HWOffsetFix<6,0,UNSIGNED> id461out_value;

  HWOffsetFix<6,0,UNSIGNED> id315out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id583out_result[2];

  HWOffsetFix<16,0,UNSIGNED> id460out_value;

  HWOffsetFix<16,0,UNSIGNED> id318out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id584out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id320out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id761out_output[91];

  HWFloat<8,24> id386out_value;

  HWOffsetFix<6,0,UNSIGNED> id459out_value;

  HWOffsetFix<1,0,UNSIGNED> id585out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id735out_output[44];

  HWOffsetFix<16,0,UNSIGNED> id458out_value;

  HWOffsetFix<16,0,UNSIGNED> id61out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id586out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id63out_io_Uz_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id726out_output[37];

  HWFloat<8,24> id66out_data;

  HWOffsetFix<1,0,UNSIGNED> id66st_read_next_cycle;
  HWFloat<8,24> id66st_last_read_value;

  HWFloat<8,24> id121out_result[9];

  HWFloat<8,24> id730out_output[12];

  HWOffsetFix<6,0,UNSIGNED> id457out_value;

  HWOffsetFix<1,0,UNSIGNED> id587out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id729out_output[32];

  HWFloat<8,24> id113out_value;

  HWFloat<8,24> id114out_result[2];

  HWFloat<8,24> id122out_result[12];

  HWOffsetFix<16,0,UNSIGNED> id456out_value;

  HWOffsetFix<16,0,UNSIGNED> id68out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id588out_result[2];

  HWOffsetFix<6,0,UNSIGNED> id455out_value;

  HWOffsetFix<1,0,UNSIGNED> id589out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id72out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id73out_io_Wz_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id733out_output[36];

  HWFloat<8,24> id76out_data;

  HWOffsetFix<1,0,UNSIGNED> id76st_read_next_cycle;
  HWFloat<8,24> id76st_last_read_value;

  HWFloat<8,24> id118out_result[9];

  HWFloat<8,24> id119out_result[12];

  HWFloat<8,24> id120out_result[12];

  HWFloat<8,24> id123out_result[2];

  HWFloat<8,24> id750out_output[2];

  HWFloat<8,24> id786out_output[2];

  HWFloat<8,24> id787out_output[2];

  HWFloat<8,24> id788out_output[2];

  HWFloat<8,24> id789out_output[2];

  HWFloat<8,24> id454out_value;

  HWOffsetFix<1,0,UNSIGNED> id322out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id760out_output[12];

  HWFloat<8,24> id453out_value;

  HWOffsetFix<1,0,UNSIGNED> id324out_result[3];

  HWFloat<8,24> id452out_value;

  HWOffsetFix<1,0,UNSIGNED> id326out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id327out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id759out_output[10];

  HWFloat<8,24> id451out_value;

  HWOffsetFix<1,0,UNSIGNED> id333out_result[3];

  HWFloat<8,24> id450out_value;

  HWOffsetFix<1,0,UNSIGNED> id335out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id336out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id757out_output[9];

  HWFloat<8,24> id449out_value;

  HWOffsetFix<1,0,UNSIGNED> id342out_result[3];

  HWFloat<8,24> id448out_value;

  HWOffsetFix<1,0,UNSIGNED> id344out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id345out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id755out_output[8];

  HWFloat<8,24> id447out_value;

  HWOffsetFix<1,0,UNSIGNED> id351out_result[3];

  HWFloat<8,24> id446out_value;

  HWOffsetFix<1,0,UNSIGNED> id353out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id354out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id753out_output[7];

  HWFloat<8,24> id445out_value;

  HWOffsetFix<1,0,UNSIGNED> id360out_result[3];

  HWFloat<8,24> id444out_value;

  HWOffsetFix<1,0,UNSIGNED> id362out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id363out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id751out_output[6];

  HWFloat<8,24> id443out_value;

  HWOffsetFix<1,0,UNSIGNED> id369out_result[3];

  HWFloat<8,24> id442out_value;

  HWOffsetFix<1,0,UNSIGNED> id371out_result[3];

  HWOffsetFix<1,0,UNSIGNED> id372out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id749out_output[5];

  HWFloat<8,24> id377out_value;

  HWFloat<8,24> id597out_floatOut[2];

  HWFloat<8,24> id440out_value;

  HWFloat<8,24> id376out_result[12];

  HWFloat<8,24> id378out_result[2];

  HWFloat<8,24> id598out_floatOut[2];

  HWFloat<8,24> id438out_value;

  HWFloat<8,24> id367out_result[12];

  HWFloat<8,24> id379out_result[2];

  HWFloat<8,24> id599out_floatOut[2];

  HWFloat<8,24> id436out_value;

  HWFloat<8,24> id358out_result[12];

  HWFloat<8,24> id380out_result[2];

  HWFloat<8,24> id600out_floatOut[2];

  HWFloat<8,24> id434out_value;

  HWFloat<8,24> id349out_result[12];

  HWFloat<8,24> id381out_result[2];

  HWFloat<8,24> id601out_floatOut[2];

  HWFloat<8,24> id432out_value;

  HWFloat<8,24> id340out_result[12];

  HWFloat<8,24> id382out_result[2];

  HWFloat<8,24> id602out_floatOut[2];

  HWFloat<8,24> id430out_value;

  HWFloat<8,24> id331out_result[12];

  HWFloat<8,24> id383out_result[2];

  HWFloat<8,24> id384out_value;

  HWFloat<8,24> id385out_result[2];

  HWFloat<8,24> id387out_result[2];

  HWFloat<8,24> id396out_result[12];

  HWFloat<8,24> id762out_output[6];

  HWFloat<8,24> id397out_result[9];

  HWOffsetFix<1,0,UNSIGNED> id776out_output[3];

  HWOffsetFix<6,0,UNSIGNED> id775out_output[10];

  HWFloat<8,24> id414out_doutb[3];

  HWFloat<8,24> id414sta_ram_store[53];

  std::string format_string_GRURnnKernel_3 (const char* _format_arg_format_string);
  HWFloat<8,24> id767out_output[83];

  HWFloat<8,24> id398out_result[9];

  HWFloat<8,24> id768out_output[17];

  HWFloat<8,24> id399out_result[12];

  HWFloat<8,24> id401out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id420out_value;

  HWOffsetFix<1,0,UNSIGNED> id429out_value;

  HWOffsetFix<49,0,UNSIGNED> id417out_value;

  HWOffsetFix<48,0,UNSIGNED> id418out_count;
  HWOffsetFix<1,0,UNSIGNED> id418out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id418st_count;

  HWOffsetFix<1,0,UNSIGNED> id428out_value;

  HWOffsetFix<49,0,UNSIGNED> id423out_value;

  HWOffsetFix<48,0,UNSIGNED> id424out_count;
  HWOffsetFix<1,0,UNSIGNED> id424out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id424st_count;

  HWOffsetFix<48,0,UNSIGNED> id426out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id590out_result[2];

  HWOffsetFix<5,0,UNSIGNED> id1out_n;

  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits;
  const HWOffsetFix<17,0,UNSIGNED> c_hw_fix_17_0_uns_bits_1;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_1;
  const HWOffsetFix<7,0,UNSIGNED> c_hw_fix_7_0_uns_bits_2;
  const HWOffsetFix<6,0,UNSIGNED> c_hw_fix_6_0_uns_bits;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits_1;
  const HWFloat<8,24> c_hw_flt_8_24_bits;
  const HWOffsetFix<6,0,UNSIGNED> c_hw_fix_6_0_uns_bits_1;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWOffsetFix<6,0,UNSIGNED> c_hw_fix_6_0_uns_bits_2;
  const HWOffsetFix<16,0,UNSIGNED> c_hw_fix_16_0_uns_bits_2;
  const HWOffsetFix<6,0,UNSIGNED> c_hw_fix_6_0_uns_bits_3;
  const HWFloat<8,24> c_hw_flt_8_24_bits_1;
  const HWFloat<8,24> c_hw_flt_8_24_bits_2;
  const HWFloat<8,24> c_hw_flt_8_24_bits_3;
  const HWFloat<8,24> c_hw_flt_8_24_bits_4;
  const HWFloat<8,24> c_hw_flt_8_24_bits_5;
  const HWFloat<8,24> c_hw_flt_8_24_bits_6;
  const HWFloat<8,24> c_hw_flt_8_24_0_03125val;
  const HWFloat<8,24> c_hw_flt_8_24_bits_7;
  const HWFloat<8,24> c_hw_flt_8_24_0_125val;
  const HWFloat<8,24> c_hw_flt_8_24_bits_8;
  const HWFloat<8,24> c_hw_flt_8_24_0_25val;
  const HWFloat<8,24> c_hw_flt_8_24_bits_9;
  const HWFloat<8,24> c_hw_flt_8_24_bits_10;
  const HWFloat<8,24> c_hw_flt_8_24_bits_11;
  const HWFloat<8,24> c_hw_flt_8_24_bits_12;
  const HWFloat<8,24> c_hw_flt_8_24_bits_13;
  const HWFloat<8,24> c_hw_flt_8_24_bits_14;
  const HWFloat<8,24> c_hw_flt_8_24_bits_15;
  const HWFloat<8,24> c_hw_flt_8_24_bits_16;
  const HWFloat<8,24> c_hw_flt_8_24_bits_17;
  const HWFloat<8,24> c_hw_flt_8_24_bits_18;
  const HWFloat<8,24> c_hw_flt_8_24_bits_19;
  const HWFloat<8,24> c_hw_flt_8_24_bits_20;
  const HWFloat<8,24> c_hw_flt_8_24_bits_21;
  const HWFloat<8,24> c_hw_flt_8_24_bits_22;
  const HWFloat<8,24> c_hw_flt_8_24_bits_23;
  const HWFloat<8,24> c_hw_flt_8_24_bits_24;
  const HWFloat<8,24> c_hw_flt_8_24_bits_25;
  const HWFloat<8,24> c_hw_flt_8_24_bits_26;
  const HWFloat<8,24> c_hw_flt_8_24_bits_27;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;

  void execute0();
};

}

#endif /* GRURNNKERNEL_H_ */
