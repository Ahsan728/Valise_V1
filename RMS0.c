/*
 * RMS0.c
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

#include "RMS0.h"
#include <math.h>
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Forward declaration for local functions */
static void SystemCore_setup(dsp_simulink_MovingRMS *obj);
static void SystemCore_setup(dsp_simulink_MovingRMS *obj)
{
  boolean_T flag;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->NumChannels = 1;
  obj->FrameLength = 1;
  obj->_pobj0.isInitialized = 0;
  obj->_pobj0.isInitialized = 0;
  flag = (obj->_pobj0.isInitialized == 1);
  if (flag) {
    obj->_pobj0.TunablePropsChanged = true;
  }

  obj->_pobj0.ForgettingFactor = 1.0;
  obj->pStatistic = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

/* Model step function */
void RMS0_step(void)
{
  g_dsp_internal_ExponentialMovin *obj;
  real_T a;
  real_T lambda;
  real_T pmLocal;
  real_T pwLocal;

  /* MATLABSystem: '<S1>/Moving RMS' incorporates:
   *  Inport: '<Root>/IN'
   */
  if (rtDW.obj.TunablePropsChanged) {
    rtDW.obj.TunablePropsChanged = false;
  }

  a = fabs(rtU.IN);
  obj = rtDW.obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pwN = 1.0;
    obj->pmN = 0.0;
    obj->plambda = obj->ForgettingFactor;
    obj->isSetupComplete = true;
    obj->TunablePropsChanged = false;
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    obj->plambda = obj->ForgettingFactor;
  }

  pwLocal = obj->pwN;
  pmLocal = obj->pmN;
  lambda = obj->plambda;
  a = (1.0 - 1.0 / pwLocal) * pmLocal + 1.0 / pwLocal * (a * a);
  obj->pwN = lambda * pwLocal + 1.0;
  obj->pmN = a;

  /* Outport: '<Root>/OUT' incorporates:
   *  Constant: '<S1>/CalibrationPhase1'
   *  MATLABSystem: '<S1>/Moving RMS'
   *  Product: '<S1>/Product'
   */
  rtY.OUT = sqrt(a) * 1.4901161193847656E-7;
}

/* Model initialize function */
void RMS0_initialize(void)
{
  {
    g_dsp_internal_ExponentialMovin *obj;

    /* Start for MATLABSystem: '<S1>/Moving RMS' */
    rtDW.obj.isInitialized = 0;
    rtDW.obj.NumChannels = -1;
    rtDW.obj.FrameLength = -1;
    rtDW.obj.matlabCodegenIsDeleted = false;
    SystemCore_setup(&rtDW.obj);

    /* InitializeConditions for MATLABSystem: '<S1>/Moving RMS' */
    obj = rtDW.obj.pStatistic;
    if (obj->isInitialized == 1) {
      obj->pwN = 1.0;
      obj->pmN = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S1>/Moving RMS' */
  }
}
