void LedInit(void);
enum eDirection{LEFT, RIGHT};
void LedOn(unsigned char ucLedIndeks);
extern unsigned int uiLedCounter;
void LedStep(enum eDirection(eStepDirection));
void LedStepLeft(void);
void LedStepRight(void);
