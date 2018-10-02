#ifndef COMMON_LIBRARY_H
#define	COMMON_LIBRARY_H

#include "../ProjectTypes.h"

    /** Type definition for the discretizer block
     */
    typedef struct {
        /* Config values */
        uint8_t num_ranges; /*!< Number of ranges to discretize */
        uint16_t *range_values_up; /*!< Frontiers for changing current range to upper range */
        uint16_t *range_values_down; /*!< Frontiers for changing current range to lower range */
        /* Input value */
        uint16_t input; /*!< Input variable to discretize */
        /* Product values */
        uint8_t range_up_idx; /*!< Result of the discretization against upper frontiers in range_values_up */
        uint8_t range_down_idx; /*!< Result of the discretization against lower frontiers in range_values_down */
        /* Output value */
        uint8_t range_idx; /*!< Result of the discretization */
    } t_d1d_block;

    /**
     Type definition for the time filter block */
    typedef struct {
        /* Config values */
        uint16_t stability_time; /*!< Filter time */
        /* Input value */
        uint16_t input; /*!< Input variable to filter */
        /* Product values */
        uint8_t current_state; /*!< Internal state of the FSM */
        uint16_t time; /*!< Internal time of the FSM */
        uint16_t new_value_detected; /*!< In the case a new value appears, it is stored here */
        /* Output value */
        uint16_t output; /*!< The filtered variable */
    } t_timefilter_block;

    /**
     Type definition for the flag qualifier block */
    typedef struct {
        /* Config values */
        uint16_t qualify_time; /*!< Qualification time */
        uint16_t heal_time; /*!< Healing time */
        /* Input value */
        BOOL input; /*!< Input variable to filter */
        /* Product values */
        uint8_t current_state; /*!< Internal state of the FSM */
        uint16_t time; /*!< Internal time of the FSM */
        /* Output value */
        BOOL output; /*!< The filtered variable */
    } t_flagqualifier_block;

    /**** FSM includes ****/
    /** Discretizer1D API **/
    void Discretizer1D_init(void);
    void Discretizer1D(void); /*!< Discretizes one variable into ranges, using upper and lower frontier vectors */
    void Discretizer1DUpRange_init(void);
    void Discretizer1DUpRange(void); /*!< Discretizes one variable into ranges using upper vector */
    void Discretizer1DDownRange_init(void);
    void Discretizer1DDownRange(void); /*!< Discretizes one variable into ranges using lower vector */
    void Discretizer1DSolver_init(void);
    void Discretizer1DSolver(void); /*!< Solves conflicts between upper and lower discretizations */

    extern t_d1d_block *d1d_block; /*!< Block to enable the discretization FSM to be executed as retargetable */

    /** TimeFilter API **/
    void TimeFilter_init(void);
    void TimeFilter(void); /*!< Filterss one variable in time */
    uint8_t GetCurrentTimeFilterState(void); /*!< Accessor to get the internal state of the filtering FSM */
    void SetCurrentTimeFilterState(uint8_t state); /*!< Accessor to set the internal state of the filtering FSM */

    extern t_timefilter_block *tf_block; /*!< Block to enable the time filtering FSM to be executed as retargetable */

        /** FlagQualifier API **/
    void FlagQualifier_init(void);
    void FlagQualifier(void); /*!< Filterss one variable in time */
    uint8_t GetCurrentFlagQualifierState(void); /*!< Accessor to get the internal state of the filtering FSM */
    void SetCurrentFlagQualifierState(uint8_t state); /*!< Accessor to set the internal state of the filtering FSM */

    extern t_flagqualifier_block *fq_block; /*!< Block to enable the time filtering FSM to be executed as retargetable */

#endif	/* COMMONLIBRARY_H */

