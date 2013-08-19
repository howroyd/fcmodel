/* Include files */

#include <stddef.h>
#include "blas.h"
#include "spsSupercapacitor_sfun.h"
#include "c1_spsSupercapacitor.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "spsSupercapacitor_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[19] = { "deltaV", "alpha", "Nc", "Ns",
  "S", "If", "i0", "R", "T", "F", "nargin", "nargout", "I", "Q", "V", "Vinit",
  "table", "Isd", "Vinits" };

/* Function Declarations */
static void initialize_c1_spsSupercapacitor(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance);
static void initialize_params_c1_spsSupercapacitor
  (SFc1_spsSupercapacitorInstanceStruct *chartInstance);
static void enable_c1_spsSupercapacitor(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance);
static void disable_c1_spsSupercapacitor(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_spsSupercapacitor
  (SFc1_spsSupercapacitorInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_spsSupercapacitor
  (SFc1_spsSupercapacitorInstanceStruct *chartInstance);
static void set_sim_state_c1_spsSupercapacitor
  (SFc1_spsSupercapacitorInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_spsSupercapacitor(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance);
static void sf_c1_spsSupercapacitor(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance);
static void initSimStructsc1_spsSupercapacitor
  (SFc1_spsSupercapacitorInstanceStruct *chartInstance);
static void registerMessagesc1_spsSupercapacitor
  (SFc1_spsSupercapacitorInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance, const mxArray *c1_Vinits, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_d_emlrt_marshallIn(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_spsSupercapacitor, const
  char_T *c1_identifier);
static uint8_T c1_e_emlrt_marshallIn(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_spsSupercapacitor(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_spsSupercapacitor = 0U;
}

static void initialize_params_c1_spsSupercapacitor
  (SFc1_spsSupercapacitorInstanceStruct *chartInstance)
{
}

static void enable_c1_spsSupercapacitor(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_spsSupercapacitor(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_spsSupercapacitor
  (SFc1_spsSupercapacitorInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_spsSupercapacitor
  (SFc1_spsSupercapacitorInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint8_T c1_c_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T *c1_Isd;
  real_T *c1_Vinits;
  c1_Vinits = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Isd = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3), FALSE);
  c1_hoistedGlobal = *c1_Isd;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_Vinits;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = chartInstance->c1_is_active_c1_spsSupercapacitor;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_spsSupercapacitor
  (SFc1_spsSupercapacitorInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_Isd;
  real_T *c1_Vinits;
  c1_Vinits = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Isd = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_Isd = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "Isd");
  *c1_Vinits = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    1)), "Vinits");
  chartInstance->c1_is_active_c1_spsSupercapacitor = c1_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
     "is_active_c1_spsSupercapacitor");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_spsSupercapacitor(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_spsSupercapacitor(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance)
{
}

static void sf_c1_spsSupercapacitor(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance)
{
  int32_T c1_i0;
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_I;
  real_T c1_Q;
  real_T c1_V;
  real_T c1_Vinit;
  int32_T c1_i1;
  real_T c1_table[6];
  uint32_T c1_debug_family_var_map[19];
  real_T c1_deltaV;
  real_T c1_alpha;
  real_T c1_Nc;
  real_T c1_Ns;
  real_T c1_S;
  real_T c1_If;
  real_T c1_b_i0;
  real_T c1_R;
  real_T c1_T;
  real_T c1_F;
  real_T c1_nargin = 5.0;
  real_T c1_nargout = 2.0;
  real_T c1_Isd;
  real_T c1_Vinits;
  real_T c1_A;
  real_T c1_B;
  real_T c1_x;
  real_T c1_y;
  real_T c1_b_x;
  real_T c1_b_y;
  real_T c1_b_A;
  real_T c1_b_B;
  real_T c1_c_x;
  real_T c1_c_y;
  real_T c1_d_x;
  real_T c1_d_y;
  real_T c1_e_y;
  real_T c1_c_A;
  real_T c1_c_B;
  real_T c1_e_x;
  real_T c1_f_y;
  real_T c1_f_x;
  real_T c1_g_y;
  real_T c1_h_y;
  real_T c1_a;
  real_T c1_b;
  real_T c1_i_y;
  real_T c1_b_a;
  real_T c1_j_y;
  real_T c1_d_A;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_k_y;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_c_a;
  real_T c1_b_b;
  real_T c1_l_y;
  real_T c1_d_a;
  real_T c1_c_b;
  real_T c1_m_y;
  real_T c1_e_a;
  real_T c1_d_b;
  real_T *c1_b_Vinits;
  real_T *c1_b_Isd;
  real_T *c1_b_Vinit;
  real_T *c1_b_V;
  real_T *c1_b_Q;
  real_T *c1_b_I;
  real_T (*c1_b_table)[6];
  boolean_T guard1 = FALSE;
  c1_b_Vinits = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_table = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_Vinit = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_Isd = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_Q = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_I = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_b_I, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Q, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Isd, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_V, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Vinit, 4U);
  for (c1_i0 = 0; c1_i0 < 6; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_table)[c1_i0], 5U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_b_Vinits, 6U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_I;
  c1_b_hoistedGlobal = *c1_b_Q;
  c1_c_hoistedGlobal = *c1_b_V;
  c1_d_hoistedGlobal = *c1_b_Vinit;
  c1_I = c1_hoistedGlobal;
  c1_Q = c1_b_hoistedGlobal;
  c1_V = c1_c_hoistedGlobal;
  c1_Vinit = c1_d_hoistedGlobal;
  for (c1_i1 = 0; c1_i1 < 6; c1_i1++) {
    c1_table[c1_i1] = (*c1_b_table)[c1_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_deltaV, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_alpha, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Nc, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Ns, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_S, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_If, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_i0, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_R, 7U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_T, 8U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_F, 9U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 10U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_I, 12U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_Q, 13U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_V, 14U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_Vinit, 15U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_table, 16U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Isd, 17U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Vinits, 18U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_deltaV = c1_table[0];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_alpha = c1_table[1];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_Nc = c1_table[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_Ns = c1_table[3];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_S = c1_table[4];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_If = c1_table[5];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_A = c1_If;
  c1_B = c1_S;
  c1_x = c1_A;
  c1_y = c1_B;
  c1_b_x = c1_x;
  c1_b_y = c1_y;
  c1_b_i0 = c1_b_x / c1_b_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  c1_R = 8.314472;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_T = 298.15;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
  c1_F = 96485.3383;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
  if (CV_EML_IF(0, 1, 0, c1_Vinit == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
    c1_Vinit = c1_V;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 0, c1_Q > 0.1)) {
    if (CV_EML_COND(0, 1, 1, c1_I == 0.0)) {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 1, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
      c1_b_A = c1_V;
      c1_b_B = c1_Ns;
      c1_c_x = c1_b_A;
      c1_c_y = c1_b_B;
      c1_d_x = c1_c_x;
      c1_d_y = c1_c_y;
      c1_e_y = c1_d_x / c1_d_y;
      c1_c_A = c1_Vinit;
      c1_c_B = c1_Ns;
      c1_e_x = c1_c_A;
      c1_f_y = c1_c_B;
      c1_f_x = c1_e_x;
      c1_g_y = c1_f_y;
      c1_h_y = c1_f_x / c1_g_y;
      c1_a = c1_alpha;
      c1_b = c1_e_y - (c1_h_y - c1_deltaV);
      c1_i_y = c1_a * c1_b;
      c1_b_a = c1_i_y;
      c1_j_y = c1_b_a * 96485.3383;
      c1_d_A = c1_j_y;
      c1_g_x = c1_d_A;
      c1_h_x = c1_g_x;
      c1_k_y = c1_h_x / 2478.9598268;
      c1_i_x = c1_k_y;
      c1_j_x = c1_i_x;
      c1_j_x = muDoubleScalarExp(c1_j_x);
      c1_c_a = c1_b_i0;
      c1_b_b = c1_j_x;
      c1_l_y = c1_c_a * c1_b_b;
      c1_d_a = c1_l_y;
      c1_c_b = c1_S;
      c1_m_y = c1_d_a * c1_c_b;
      c1_e_a = c1_m_y;
      c1_d_b = c1_Nc;
      c1_Isd = c1_e_a * c1_d_b;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
      c1_Vinits = c1_Vinit;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 1, FALSE);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
    c1_Isd = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
    c1_Vinits = c1_V;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -28);
  _SFD_SYMBOL_SCOPE_POP();
  *c1_b_Isd = c1_Isd;
  *c1_b_Vinits = c1_Vinits;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_spsSupercapacitorMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_spsSupercapacitor
  (SFc1_spsSupercapacitorInstanceStruct *chartInstance)
{
}

static void registerMessagesc1_spsSupercapacitor
  (SFc1_spsSupercapacitorInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_spsSupercapacitorInstanceStruct *chartInstance;
  chartInstance = (SFc1_spsSupercapacitorInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance, const mxArray *c1_Vinits, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Vinits), &c1_thisId);
  sf_mex_destroy(&c1_Vinits);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Vinits;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_spsSupercapacitorInstanceStruct *chartInstance;
  chartInstance = (SFc1_spsSupercapacitorInstanceStruct *)chartInstanceVoid;
  c1_Vinits = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Vinits), &c1_thisId);
  sf_mex_destroy(&c1_Vinits);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i2;
  real_T c1_b_inData[6];
  int32_T c1_i3;
  real_T c1_u[6];
  const mxArray *c1_y = NULL;
  SFc1_spsSupercapacitorInstanceStruct *chartInstance;
  chartInstance = (SFc1_spsSupercapacitorInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i2 = 0; c1_i2 < 6; c1_i2++) {
    c1_b_inData[c1_i2] = (*(real_T (*)[6])c1_inData)[c1_i2];
  }

  for (c1_i3 = 0; c1_i3 < 6; c1_i3++) {
    c1_u[c1_i3] = c1_b_inData[c1_i3];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_spsSupercapacitor_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[7];
  c1_ResolvedFunctionInfo (*c1_b_info)[7];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i4;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[7])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "mrdivide";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[0].fileTimeLo = 1357955148U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 1319733566U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[1].name = "rdivide";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[1].fileTimeLo = 1346513988U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[2].name = "eml_scalexp_compatible";
  (*c1_b_info)[2].dominantType = "double";
  (*c1_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c1_b_info)[2].fileTimeLo = 1286822396U;
  (*c1_b_info)[2].fileTimeHi = 0U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[3].name = "eml_div";
  (*c1_b_info)[3].dominantType = "double";
  (*c1_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c1_b_info)[3].fileTimeLo = 1313351410U;
  (*c1_b_info)[3].fileTimeHi = 0U;
  (*c1_b_info)[3].mFileTimeLo = 0U;
  (*c1_b_info)[3].mFileTimeHi = 0U;
  (*c1_b_info)[4].context = "";
  (*c1_b_info)[4].name = "mtimes";
  (*c1_b_info)[4].dominantType = "double";
  (*c1_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[4].fileTimeLo = 1289523292U;
  (*c1_b_info)[4].fileTimeHi = 0U;
  (*c1_b_info)[4].mFileTimeLo = 0U;
  (*c1_b_info)[4].mFileTimeHi = 0U;
  (*c1_b_info)[5].context = "";
  (*c1_b_info)[5].name = "exp";
  (*c1_b_info)[5].dominantType = "double";
  (*c1_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  (*c1_b_info)[5].fileTimeLo = 1343833980U;
  (*c1_b_info)[5].fileTimeHi = 0U;
  (*c1_b_info)[5].mFileTimeLo = 0U;
  (*c1_b_info)[5].mFileTimeHi = 0U;
  (*c1_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  (*c1_b_info)[6].name = "eml_scalar_exp";
  (*c1_b_info)[6].dominantType = "double";
  (*c1_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  (*c1_b_info)[6].fileTimeLo = 1301332064U;
  (*c1_b_info)[6].fileTimeHi = 0U;
  (*c1_b_info)[6].mFileTimeLo = 0U;
  (*c1_b_info)[6].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 7), FALSE);
  for (c1_i4 = 0; c1_i4 < 7; c1_i4++) {
    c1_r0 = &c1_info[c1_i4];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i4);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_spsSupercapacitorInstanceStruct *chartInstance;
  chartInstance = (SFc1_spsSupercapacitorInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i5;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i5, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i5;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_spsSupercapacitorInstanceStruct *chartInstance;
  chartInstance = (SFc1_spsSupercapacitorInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_spsSupercapacitor, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_spsSupercapacitor), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_spsSupercapacitor);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_spsSupercapacitorInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_spsSupercapacitor_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3188507400U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1937341168U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(942095927U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4057608386U);
}

mxArray *sf_c1_spsSupercapacitor_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NyV55t17w9Qo2DzoeFIR7E");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_spsSupercapacitor_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_spsSupercapacitor(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"Isd\",},{M[1],M[17],T\"Vinits\",},{M[8],M[0],T\"is_active_c1_spsSupercapacitor\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_spsSupercapacitor_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_spsSupercapacitorInstanceStruct *chartInstance;
    chartInstance = (SFc1_spsSupercapacitorInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _spsSupercapacitorMachineNumber_,
           1,
           1,
           1,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_spsSupercapacitorMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_spsSupercapacitorMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _spsSupercapacitorMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"I");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Q");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Isd");
          _SFD_SET_DATA_PROPS(3,1,1,0,"V");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Vinit");
          _SFD_SET_DATA_PROPS(5,1,1,0,"table");
          _SFD_SET_DATA_PROPS(6,2,0,1,"Vinits");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,589);
        _SFD_CV_INIT_EML_IF(0,1,0,401,412,-1,429);
        _SFD_CV_INIT_EML_IF(0,1,1,431,451,555,588);

        {
          static int condStart[] = { 435, 446 };

          static int condEnd[] = { 440, 450 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,434,451,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_I;
          real_T *c1_Q;
          real_T *c1_Isd;
          real_T *c1_V;
          real_T *c1_Vinit;
          real_T *c1_Vinits;
          real_T (*c1_table)[6];
          c1_Vinits = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_table = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 4);
          c1_Vinit = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_V = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_Isd = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_Q = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_I = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_I);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_Q);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_Isd);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_V);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_Vinit);
          _SFD_SET_DATA_VALUE_PTR(5U, *c1_table);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_Vinits);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _spsSupercapacitorMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "fYgncTSB9qH4xffLyTDaYD";
}

static void sf_opaque_initialize_c1_spsSupercapacitor(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_spsSupercapacitorInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_spsSupercapacitor((SFc1_spsSupercapacitorInstanceStruct*)
    chartInstanceVar);
  initialize_c1_spsSupercapacitor((SFc1_spsSupercapacitorInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_spsSupercapacitor(void *chartInstanceVar)
{
  enable_c1_spsSupercapacitor((SFc1_spsSupercapacitorInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_spsSupercapacitor(void *chartInstanceVar)
{
  disable_c1_spsSupercapacitor((SFc1_spsSupercapacitorInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_spsSupercapacitor(void *chartInstanceVar)
{
  sf_c1_spsSupercapacitor((SFc1_spsSupercapacitorInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_spsSupercapacitor(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_spsSupercapacitor
    ((SFc1_spsSupercapacitorInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_spsSupercapacitor();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_spsSupercapacitor(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_spsSupercapacitor();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_spsSupercapacitor((SFc1_spsSupercapacitorInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_spsSupercapacitor(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_spsSupercapacitor(S);
}

static void sf_opaque_set_sim_state_c1_spsSupercapacitor(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_spsSupercapacitor(S, st);
}

static void sf_opaque_terminate_c1_spsSupercapacitor(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_spsSupercapacitorInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_spsSupercapacitor_optimization_info();
    }

    finalize_c1_spsSupercapacitor((SFc1_spsSupercapacitorInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_spsSupercapacitor((SFc1_spsSupercapacitorInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_spsSupercapacitor(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_spsSupercapacitor((SFc1_spsSupercapacitorInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_spsSupercapacitor(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_spsSupercapacitor_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1052182249U));
  ssSetChecksum1(S,(3063022640U));
  ssSetChecksum2(S,(1229821205U));
  ssSetChecksum3(S,(455638336U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_spsSupercapacitor(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_spsSupercapacitor(SimStruct *S)
{
  SFc1_spsSupercapacitorInstanceStruct *chartInstance;
  chartInstance = (SFc1_spsSupercapacitorInstanceStruct *)utMalloc(sizeof
    (SFc1_spsSupercapacitorInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_spsSupercapacitorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_spsSupercapacitor;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_spsSupercapacitor;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_spsSupercapacitor;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_spsSupercapacitor;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_spsSupercapacitor;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_spsSupercapacitor;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_spsSupercapacitor;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_spsSupercapacitor;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_spsSupercapacitor;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_spsSupercapacitor;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_spsSupercapacitor;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_spsSupercapacitor_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_spsSupercapacitor(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_spsSupercapacitor(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_spsSupercapacitor(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_spsSupercapacitor_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
