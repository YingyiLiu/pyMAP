#include "MAP_OtherStateType.h"
#include "NWTCFunctions.h"
#include "MAP_Types.h"
#include "MAP_ErrStat.h"
#include "MAP_Message.h"


// ==========   MAP Object Con/Destructor   ===============     <---------------------------------+
//                                                                                    //          |
// This creates instance of MAP objects in Fortran.                                   //          |
// Note: The interface for these methods (both the constructor and destructor)        //          |
//       is in MAP_C_Types.f90, which is auto-generated by the FAST registry.         //          |
                                                                                      //          |
extern "C" CALL MAP_Message_class*                                                    //          |
MAP_Message_Create( ){ return new MAP_Message_class( ); };                            //          |
                                                                                      //          |
extern "C" CALL MAP_ErrStat_class*                                                    //          |
MAP_ErrStat_Create( ){ return new MAP_ErrStat_class( ); };                            //          |
                                                                                      //          |
extern "C"  CALL void                                                                 //          |
MAP_Message_Delete( MAP_Message_class *This ){ delete This; }                         //          |
                                                                                      //          |
extern "C"  CALL void                                                                 //          |
MAP_ErrStat_Delete( MAP_ErrStat_class *This ){ delete This; }                         //   -------+
//=================================================================================================


typedef struct MAP_Message {
  void * object ;
} MAP_Message_class_class_t ;
typedef struct MAP_ErrStat {
  void * object ;
} MAP_ErrStat_class_class_t ;


extern "C" CALL std::string PyCALL_MAP_Message_SetMessage( MAP_Message *Msg ) { 
  MAP_Message_class *msg = static_cast<MAP_Message_class*>(Msg->object);
  return msg->GetErrorMessage(); 
};


extern "C" CALL std::string PyCALL_MAP_Message_SetConvergeReason( MAP_Message *Msg ) { 
  MAP_Message_class *msg = static_cast<MAP_Message_class*>(Msg->object);
  return msg->GetConvergeReason();
};


extern "C" CALL int PyCALL_MAP_ErrStat_SetErrorStatus( MAP_ErrStat *Err ) { 
  MAP_ErrStat_class *err = static_cast<MAP_ErrStat_class*>(Err->object);
  return err->error_status();
};


extern "C" CALL void PyCALL_GetPlotArrays( MAP_OtherStateType *OtherData ,     
                                           int                 &i        , 
                                           std::vector<double> &vec_x    , 
                                           std::vector<double> &vec_y    , 
                                           std::vector<double> &vec_z    , 
                                           MAP_ErrStat         *Err      , 
                                           MAP_Message         *Msg      )
{
  MAP_OtherStateType_class *other = static_cast<MAP_OtherStateType_class*>(OtherData->object);
  MAP_ErrStat_class *err = static_cast<MAP_ErrStat_class*>(Err->object);
  MAP_Message_class *msg = static_cast<MAP_Message_class*>(Msg->object);
  
  other->GetPyPlotArray( i, vec_x, vec_y, vec_z, *err, *msg );
};



extern "C" CALL void
PyCALL_MSQS_Init( MAP_InitInputType       *InitInp     ,     
                  MAP_InputType           *InputData   ,     
                  MAP_ParameterType       *ParamData   ,     
                  MAP_ContinuousStateType *ContData    ,     
                  MAP_DiscreteStateType   *DiscData    ,     
                  MAP_ConstraintStateType *ConstrData  ,     
                  MAP_OtherStateType      *OtherData   ,     
                  MAP_OutputType          *OutData     ,     
                  MAP_InitOutputType      *InitOutData ,     
                  MAP_ErrStat             *Stat        ,     
                  MAP_Message             *Msg         )  
{
  void* Nothing = NULL;  
  
  MAP_InitInputType_class *inp = static_cast<MAP_InitInputType_class*>(InitInp->object);
  MAP_InputType_class *u = static_cast<MAP_InputType_class*>(InputData->object);
  MAP_ParameterType_class *p = static_cast<MAP_ParameterType_class*>(ParamData->object);
  MAP_ConstraintStateType_class *z = static_cast<MAP_ConstraintStateType_class*>(ConstrData->object);
  MAP_OtherStateType_class *o = static_cast<MAP_OtherStateType_class*>(OtherData->object);
  MAP_OutputType_class *y = static_cast<MAP_OutputType_class*>(OutData->object);
  MAP_InitOutputType_class *out = static_cast<MAP_InitOutputType_class*>(InitOutData->object);
  MAP_ErrStat_class *err = static_cast<MAP_ErrStat_class*>(Stat->object);
  MAP_Message_class *msg = static_cast<MAP_Message_class*>(Msg->object);

  MSQS_Init( *inp    , 
             *u      , 
             *p      , 
             Nothing , 
             Nothing , 
             *z      , 
             *o      , 
             *y      , 
             Nothing , 
             *out    , 
             *err    , 
             *msg    );
};

extern "C" CALL void 
PyCALL_MSQS_UpdateStates( float                   time         ,
                          int                     N            ,
                          MAP_InputType           *InputData   ,     
                          MAP_ParameterType       *ParamData   ,     
                          MAP_ContinuousStateType *ContData    ,     
                          MAP_DiscreteStateType   *DiscData    ,     
                          MAP_ConstraintStateType *ConstrData  ,     
                          MAP_OtherStateType      *OtherData   ,     
                          MAP_ErrStat             *Stat        ,     
                          MAP_Message             *Msg         )  
{
  void* Nothing = NULL;  
  
  MAP_InputType_class *u = static_cast<MAP_InputType_class*>(InputData->object);
  MAP_ParameterType_class *p = static_cast<MAP_ParameterType_class*>(ParamData->object);
  MAP_ConstraintStateType_class *z = static_cast<MAP_ConstraintStateType_class*>(ConstrData->object);
  MAP_OtherStateType_class *o = static_cast<MAP_OtherStateType_class*>(OtherData->object);
  MAP_ErrStat_class *err = static_cast<MAP_ErrStat_class*>(Stat->object);
  MAP_Message_class *msg = static_cast<MAP_Message_class*>(Msg->object);
  
  MSQS_UpdateStates( time    ,                                                                    
                     N       ,                                                                    
                     *u      ,
                     *p      ,
                     Nothing ,                                                                    
                     Nothing ,                                                                    
                     *z      ,
                     *o      ,
                     *err     ,                                                                    
                     *msg     );
}


extern "C" CALL void 
PyCALL_MSQS_CalcOutput( float                   time         ,
                        MAP_InputType           *InputData   ,     
                        MAP_ParameterType       *ParamData   ,     
                        MAP_ContinuousStateType *ContData    ,     
                        MAP_DiscreteStateType   *DiscData    ,     
                        MAP_ConstraintStateType *ConstrData  ,     
                        MAP_OtherStateType      *OtherData   ,     
                        MAP_OutputType          *OutData     ,     
                        MAP_ErrStat             *Stat        ,     
                        MAP_Message             *Msg         )  
{
  void* Nothing = NULL;  
  
  MAP_InputType_class *u = static_cast<MAP_InputType_class*>(InputData->object);
  MAP_ParameterType_class *p = static_cast<MAP_ParameterType_class*>(ParamData->object);
  MAP_ConstraintStateType_class *z = static_cast<MAP_ConstraintStateType_class*>(ConstrData->object);
  MAP_OtherStateType_class *o = static_cast<MAP_OtherStateType_class*>(OtherData->object);
  MAP_OutputType_class *y = static_cast<MAP_OutputType_class*>(OutData->object);
  MAP_ErrStat_class *err = static_cast<MAP_ErrStat_class*>(Stat->object);
  MAP_Message_class *msg = static_cast<MAP_Message_class*>(Msg->object);

  MSQS_CalcOutput( time    ,                                                
                   *u      ,
                   *p      ,
                   Nothing ,                                                
                   Nothing ,                                                
                   *z      ,
                   *o      ,
                   *y      ,
                   *err     ,                                                
                   *msg     );                                                                 
}


extern "C" CALL void 
PyCALL_MSQS_End( MAP_InputType           *InputData   ,     
                 MAP_ParameterType       *ParamData   ,     
                 MAP_ContinuousStateType *ContData    ,     
                 MAP_DiscreteStateType   *DiscData    ,     
                 MAP_ConstraintStateType *ConstrData  ,     
                 MAP_OtherStateType      *OtherData   ,     
                 MAP_OutputType          *OutData     ,     
                 MAP_ErrStat             *Stat        ,     
                 MAP_Message             *Msg         )  
{
  void* Nothing = NULL;  
  
  MAP_InputType_class *u = static_cast<MAP_InputType_class*>(InputData->object);
  MAP_ParameterType_class *p = static_cast<MAP_ParameterType_class*>(ParamData->object);
  MAP_ConstraintStateType_class *z = static_cast<MAP_ConstraintStateType_class*>(ConstrData->object);
  MAP_OtherStateType_class *o = static_cast<MAP_OtherStateType_class*>(OtherData->object);
  MAP_OutputType_class *y = static_cast<MAP_OutputType_class*>(OutData->object);
  MAP_ErrStat_class *err = static_cast<MAP_ErrStat_class*>(Stat->object);
  MAP_Message_class *msg = static_cast<MAP_Message_class*>(Msg->object);

  MSQS_End( *u      , 
            *p      , 
            Nothing , 
            Nothing , 
            *z      , 
            *o      , 
            *y      , 
            *err    , 
            *msg    );
}

