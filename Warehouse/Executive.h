#ifndef EXECUTIVE_H_
#define EXECUTIVE_H_

#include "Member.h"

class Executive : public Member {
public:
	Price rebate_amount; //Keep this this way. See res/Public_Variables_Manifesto
	Executive() { rebate_amount.cents = 0;  rebate_amount.dollars = 0; member_type = EXECUTIVE; }
	~Executive() {}
};

#endif /* EXECUTIVE_H_ */
