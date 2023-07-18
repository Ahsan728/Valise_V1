/*
 * RMS0.h
 *
 * Code generation for model "RMS0".
 *
 * Model version              : 8.20
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Tue Jul 18 14:22:45 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RMS0_h_
#define RTW_HEADER_RMS0_h_
#ifndef RMS0_COMMON_INCLUDES_
#define RMS0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* RMS0_COMMON_INCLUDES_ */

#ifndef struct_tag_xm5q3dGCROLmOPhUk992jB
#define struct_tag_xm5q3dGCROLmOPhUk992jB

struct tag_xm5q3dGCROLmOPhUk992jB
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  real_T ForgettingFactor;
  real_T pwN;
  real_T pmN;
  real_T plambda;
};

#endif                                 /* struct_tag_xm5q3dGCROLmOPhUk992jB */

#ifndef typedef_g_dsp_internal_ExponentialMovin
#define typedef_g_dsp_internal_ExponentialMovin

typedef struct tag_xm5q3dGCROLmOPhUk992jB g_dsp_internal_ExponentialMovin;

#endif                             /* typedef_g_dsp_internal_ExponentialMovin */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap
#define typedef_cell_wrap

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap;

#endif                                 /* typedef_cell_wrap */

#ifndef struct_tag_4cCnIZk3PKZ5pfZVNQa5jB
#define struct_tag_4cCnIZk3PKZ5pfZVNQa5jB

struct tag_4cCnIZk3PKZ5pfZVNQa5jB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap inputVarSize;
  g_dsp_internal_ExponentialMovin *pStatistic;
  int32_T NumChannels;
  int32_T FrameLength;
  g_dsp_internal_ExponentialMovin _pobj0;
};

#endif                                 /* struct_tag_4cCnIZk3PKZ5pfZVNQa5jB */

#ifndef typedef_dsp_simulink_MovingRMS
#define typedef_dsp_simulink_MovingRMS

typedef struct tag_4cCnIZk3PKZ5pfZVNQa5jB dsp_simulink_MovingRMS;

#endif                                 /* typedef_dsp_simulink_MovingRMS */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingRMS obj;          /* '<S1>/Moving RMS' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T IN;                           /* '<Root>/IN' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T OUT;                          /* '<Root>/OUT' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void RMS0_initialize(void);
extern void RMS0_step(void);
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('FeaturesExtraction_V2/RMS')    - opens subsystem FeaturesExtraction_V2/RMS
 * hilite_system('FeaturesExtraction_V2/RMS/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FeaturesExtraction_V2'
 * '<S1>'   : 'FeaturesExtraction_V2/RMS'
 */
#endif                                 /* RTW_HEADER_RMS0_h_ */
