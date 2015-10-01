#ifndef REGULAR_H_
#define REGULAR_H_

#include "Member.h"

class Regular : public Member {
public:
	Regular() { member_type = REGULAR; }
	~Regular() {}
};

#endif /* REGULAR_H_ */
