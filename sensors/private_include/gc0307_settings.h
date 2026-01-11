#ifndef _GC0307_SETTINGS_H_
#define _GC0307_SETTINGS_H_

#include <stdint.h>

#define REG_DLY 0xff
//#define ENDMARKER { 0xff, 0xff }
static const uint8_t gc0307_sensor_default_regs[][2] = {
// Initail Sequence Write In.
//========= close output
{  0x43  ,0x00}, 
{  0x44  ,0xa2}, 

//========= close some functions
// open them after configure their parmameters
{  0x40  ,0x10}, 
{  0x41  ,0x00},           
{  0x42  ,0x10},                       
//    {  0x47  ,0x80}, //mode1,   
//  {  0x47  ,0x00}, //mode1,                  
{  0x48  ,0xc3}, //mode2,  
{  0x49  ,0x00}, //dither_mode         
{  0x4a  ,0x00}, //clock_gating_en
{  0x4b  ,0x00}, //mode_reg3
{  0x4E  ,0x23}, //sync mode
{  0x4F  ,0x01}, //AWB, AEC, every N frame 

//========= frame timing
{  0x01  ,0x6a}, //HB
//    {  0x02  ,0x25}, //VB//0c//70
{  0x02  ,0x70}, //VB//0c//70
//    {  0x1C  ,0x00}, //Vs_st//02
{  0x1C  ,0x02}, //Vs_st//02
//    {  0x1D  ,0x00}, //Vs_et//02
{  0x1D  ,0x02}, //Vs_et//02
{  0x10  ,0x00}, //high 4 bits of VB, HB
{  0x11  ,0x05}, //row_tail,  AD_pipe_number

{  0x03  ,0x01}, //row_start
{  0x04  ,0x2c},

//========= windowing
{  0x05  ,0x00}, //row_start
{  0x06  ,0x00},
{  0x07  ,0x00}, //col start
{  0x08  ,0x02}, 
{  0x09  ,0x01}, //win height
{  0x0A  ,0xE8},
{  0x0B  ,0x02}, //win width, pixel array only 640
//    {  0x0C  ,0x82},
{  0x0C  ,0x80},
//========= analog
{  0x0D  ,0x22}, //rsh_width
{  0x0E  ,0x02}, //CISCTL mode2,  
{  0x0F  ,0x82}, //CISCTL mode1


{  0x12  ,0x70}, //7 hrst, 6_4 darsg,
{  0x13  ,0x00}, //7 CISCTL_restart, 0 apwd
{  0x14  ,0x00}, //NA
{  0x15  ,0xba}, //7_4 vref
{  0x16  ,0x13}, //5to4 _coln_r,  __1to0__da18
{  0x17  ,0x52}, //opa_r, ref_r, sRef_r
{  0x18  ,0xc0}, //analog_mode, best case for left band.

{  0x1E  ,0x0d}, //tsp_width          
{  0x1F  ,0x32}, //sh_delay

//========= offset
//    {  0x47  ,0x80},  //7__test_image, __6__fixed_pga, __5__auto_DN, __4__CbCr_fix, //80
//    {  0x47  ,0x00},  //7__test_image, __6__fixed_pga, __5__auto_DN, __4__CbCr_fix, //80
//__3to2__dark_sequence, __1__allow_pclk_vcync, __0__LSC_test_image
{  0x19  ,0x06},  //pga_o           
{  0x1a  ,0x06},  //pga_e           

{  0x31  ,0x00},  //4  //pga_oFFset ,   high 8bits of 11bits
{  0x3B  ,0x00},  //global_oFFset, low 8bits of 11bits

{  0x59  ,0x0f},  //offset_mode    
{  0x58  ,0x88},  //DARK_VALUE_RATIO_G,  DARK_VALUE_RATIO_RB
{  0x57  ,0x08},  //DARK_CURRENT_RATE
{  0x56  ,0x77},  //PGA_OFFSET_EVEN_RATIO, PGA_OFFSET_ODD_RATIO

//========= blk
{  0x35  ,0xd8},  //blk_mode

{  0x36  ,0x40},  

{  0x3C  ,0x00}, 
{  0x3D  ,0x00}, 
{  0x3E  ,0x00}, 
{  0x3F  ,0x00}, 

{  0xb5  ,0x70}, 
{  0xb6  ,0x40}, 
{  0xb7  ,0x00}, 
{  0xb8  ,0x38}, 
{  0xb9  ,0xc3},         
{  0xba  ,0x0f}, 

{  0x7e  ,0x35}, 
{  0x7f  ,0x86}, 

{  0x5c  ,0x68}, //78
{  0x5d  ,0x68}, //88


//========= manual_gain 
{  0x61  ,0x80}, //manual_gain_g1  
{  0x63  ,0x80}, //manual_gain_r
{  0x65  ,0x98}, //manual_gai_b, 0xa0=1.25, 0x98=1.1875
{  0x67  ,0x80}, //manual_gain_g2
{  0x68  ,0x18}, //global_manual_gain   2.4bits

//=========CC _R
{  0x69  ,0x58},  //54//58
{  0x6A  ,0xf6},  //ff
{  0x6B  ,0xfb},  //fe
{  0x6C  ,0xf4},  //ff
{  0x6D  ,0x5a},  //5f
{  0x6E  ,0xe6},  //e1

{  0x6f  ,0x00},   

//=========lsc                            
{  0x70  ,0x14}, 
{  0x71  ,0x1c}, 
{  0x72  ,0x20}, 

{  0x73  ,0x10},   
{  0x74  ,0x3c}, 
{  0x75  ,0x52}, 

//=========dn                                                                            
{  0x7d  ,0x2f},  //dn_mode    
{  0x80  ,0x0c}, //when auto_dn, check 7e,7f
{  0x81  ,0x0c},
{  0x82  ,0x44},
											
//dd                                                                           
{  0x83  ,0x18},  //DD_TH1                       
{  0x84  ,0x18},  //DD_TH2                       
{  0x85  ,0x04},  //DD_TH3                                                                                               
{  0x87  ,0x34},  //32 b DNDD_low_range X16,  DNDD_low_range_C_weight_center                   


//=========intp-ee                                                                         
{  0x88  ,0x04},                                                      
{  0x89  ,0x01},                                         
{  0x8a  ,0x50},//60                                          
{  0x8b  ,0x50},//60                                          
{  0x8c  ,0x07},                                                                 
										  
{  0x50  ,0x0c},                                   
{  0x5f  ,0x3c},                                                                                    
										 
{  0x8e  ,0x02},                                                             
{  0x86  ,0x02},                                                                 
										
{  0x51  ,0x20},                                                               
{  0x52  ,0x08},  
{  0x53  ,0x00}, 


//========= YCP 
//contrast_center                                                                             
{  0x77  ,0x80}, //contrast_center                                                                   
{  0x78  ,0x00}, //fixed_Cb                                                                          
{  0x79  ,0x00}, //fixed_Cr                                                                          
{  0x7a  ,0x00}, //luma_offset                                                                                                                                                             
{  0x7b  ,0x40}, //hue_cos                                                                           
{  0x7c  ,0x00}, //hue_sin                                                                           
												 
//saturation                                                                                  
{  0xa0  ,0x40}, //global_saturation
{  0xa1  ,0x40}, //luma_contrast                                                                     
{  0xa2  ,0x34}, //saturation_Cb//0x34                                                                   
{  0xa3  ,0x34}, //saturation_Cr//0x34
									
{  0xa4  ,0xc8},                                                                 
{  0xa5  ,0x02}, 
{  0xa6  ,0x28},                                                                             
{  0xa7  ,0x02}, 

//skin                                                                                                
{  0xa8  ,0xee},                                                             
{  0xa9  ,0x12},                                                             
{  0xaa  ,0x01},                                                         
{  0xab  ,0x20},                                                     
{  0xac  ,0xf0},                                                         
{  0xad  ,0x10},                                                             

//========= ABS
{  0xae  ,0x18}, 
{  0xaf  ,0x74}, 
{  0xb0  ,0xe0},     
{  0xb1  ,0x20}, 
{  0xb2  ,0x6c}, 
{  0xb3  ,0x40}, 
{  0xb4  ,0x04}, 

//========= AWB 
{  0xbb  ,0x42}, 
{  0xbc  ,0x60}, 
{  0xbd  ,0x50}, 
{  0xbe  ,0x50}, 

{  0xbf  ,0x0c}, 
{  0xc0  ,0x06}, 
{  0xc1  ,0x70}, 
{  0xc2  ,0xf1},  //f4
{  0xc3  ,0x40}, 
{  0xc4  ,0x1c}, //18
{  0xc5  ,0x56}, 
{  0xc6  ,0x1d},   

{  0xca  ,0x56}, //0x70
{  0xcb  ,0x52}, //0x70
{  0xcc  ,0x66}, //0x78

{  0xcd  ,0x80}, //R_ratio                                      
{  0xce  ,0x80}, //G_ratio  , cold_white white                                    
{  0xcf  ,0x80}, //B_ratio     

//=========  aecT  
{  0x20  ,0x06}, //02
{  0x21  ,0xc0}, 
{  0x22  ,0x60},    
{  0x23  ,0x88}, 
{  0x24  ,0x96}, 
{  0x25  ,0x30}, 
{  0x26  ,0xd0}, 
{  0x27  ,0x00}, 

{  0x28  ,0x02}, //AEC_exp_level_1bit11to8   
{  0x29  ,0x0d}, //AEC_exp_level_1bit7to0    
{  0x2a  ,0x02}, //AEC_exp_level_2bit11to8   
{  0x2b  ,0x0d}, //AEC_exp_level_2bit7to0           
{  0x2c  ,0x02}, //AEC_exp_level_3bit11to8   659 - 8FPS,  8ca - 6FPS  //    
{  0x2d  ,0x0d}, //AEC_exp_level_3bit7to0           
{  0x2e  ,0x05}, //AEC_exp_level_4bit11to8   4FPS 
{  0x2f  ,0xdc}, //AEC_exp_level_4bit7to0   

{  0x30  ,0x20},                         
{  0x31  ,0x00},                      
{  0x32  ,0x1c}, 
{  0x33  ,0x90},             
{  0x34  ,0x10},   

{  0xd0  ,0x34}, 

{  0xd1  ,0x50}, //AEC_target_Y//0x50                         
{  0xd2  ,0x61},//f2     
{  0xd4  ,0x4b}, //96
{  0xd5  ,0x01},// 10 
{  0xd6  ,0x4b}, //antiflicker_step //96                      
{  0xd7  ,0x03}, //AEC_exp_time_min //10              
{  0xd8  ,0x02}, 

{  0xdd  ,0x12}, 
					
//========= measure window                                      
{  0xe0  ,0x03},                        
{  0xe1  ,0x02},                            
{  0xe2  ,0x27},                                
{  0xe3  ,0x1e},                
{  0xe8  ,0x3b},                    
{  0xe9  ,0x6e},                        
{  0xea  ,0x2c},                    
{  0xeb  ,0x50},                    
{  0xec  ,0x73},        

//=========for the picture mirror=======
//********** 0  -> IMAGE_NORMAL  1  -> IMAGE_H_MIRROR  2  ->IMAGE_V_MIRROR  3  -> IMAGE_HV_MIRROR  *****//
{0x0f,0xb2}, // b0
{0x45,0x24}, //Gr first
//=========end picture mirror ===========
{  0x40  ,0x10}, //7e
{  0x41  ,0x00}, //2f

{  0x4d  ,0x20},
};

#endif
