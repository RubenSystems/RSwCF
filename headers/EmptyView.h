//
//  EmptyView.h
//  RSwCF
//
//  Created by Ruben Ticehurst-James on 11/08/2022.
//

#ifndef EmptyView_h
#define EmptyView_h

#include "Generatable.h"

namespace rswcf {
	class EmptyView: public Generatable {
		public:
			EmptyView() {}
		
			GeneratedResult generate() {
				GeneratedResult empty;
				return empty;
			}
		
	};
	
	EmptyView * empty_view() {
		return new EmptyView();
	}
}

#endif /* EmptyView_h */
