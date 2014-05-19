#ifndef NEBULA_UTIL_PARENT_HH
#define NEBULA_UTIL_PARENT_HH

#include <Nebula/Types.hh>
#include <Nebula/Util/Address.hh>
#include <Nebula/Util/Map.hh>
#include <Nebula/Util/WrapperTyped.hh>


namespace Neb {
	namespace Util {
		template<class T> class Parent {
			public:
				typedef T			__type_type;
				typedef std::shared_ptr<T>	__shared_type;
				typedef Neb::WrapperTyped<T>	__wrapper_type;
				typedef Neb::Map<T>		__map_type;
				
				typedef Neb::Util::Address<T>	__address_type;
				typedef Neb::Util::index_type	__index_type;
	
				Parent();

				void					insert(__shared_type s);
				void					insert(__shared_type s, int i);
				
				__shared_type				get(__index_type i) {
					auto it = actors_.find(i);
					if(it == actors_.end()) return __shared_type;
					return it->second.ptr_;
				}
				__shared_type				get(Neb::Util::Address_ a) {
	
				}
					if(a.vec_.empty()) return __shared_type;
					
					std::shared_ptr<Neb::Util::IndexBase> = a.vec_.front();
					
					a.vec_.pop_front();
					
					auto i = std::dynamic_ pointer_cast<Neb::Util::Index<T> >(ib);
					sNeb::Util::Parent
				}

				void					releaseActor(__index_type i);




				__map_type				map_;
		};
	}
}

#endif
