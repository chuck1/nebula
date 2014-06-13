#ifndef __NEBULA_UI_LAYOUT_BASE_HPP__
#define __NEBULA_UI_LAYOUT_BASE_HPP__

#include <map>

#include <Nebula/Graphics/Types.hh>
#include <Nebula/Graphics/GUI/Object/Base.hh>
//#include <Nebula/Graphics/GUI/Layout/Util/Parent.hh>
#include <Nebula/Graphics/GUI/Object/Util/Parent.hh>
#include <Nebula/Graphics/Drawable/Base.hpp>

#include <Nebula/Graphics/Window/Base.hh>
#include <Nebula/Util/typedef.hpp>

namespace neb {
	namespace gfx {
		namespace gui {
			namespace Layout {
			/** @brief %Base */
				class Base:
					virtual public neb::std::shared,
					virtual public neb::gfx::Drawable::Base,
					virtual public neb::gfx::gui::object::Util::Parent
				{
					public:
						Base();
						Base(sp::shared_ptr<neb::gfx::gui::Layout::Util::Parent> parent);

						virtual void				init();


						/** @brief Main Loop @{ */
						virtual void					step(neb::core::TimeStep const & ts);
						virtual void					draw(sp::shared_ptr<neb::gfx::Context::Base> context, sp::shared_ptr<neb::glsl::program> p);
						/** @} */

						void						connect(
								sp::shared_ptr<neb::gfx::Window::Base> const & window);
						int						search(
								sp::shared_ptr<neb::gfx::Window::Base> const & ,int button, int action, int mods);
						int						mouse_button_fun(
								sp::shared_ptr<neb::gfx::Window::Base> const & ,int button, int action, int mods);
						int						key_fun(
								sp::shared_ptr<neb::gfx::Window::Base> const & ,int,int,int,int);
					public:
						glm::mat4x4					ortho_;


						sp::shared_ptr<neb::gfx::gui::Layout::Util::Parent>	parent_;
						// connections
						struct
						{
							boost::signals2::connection		mouse_button_fun_;
							boost::signals2::connection		key_fun_;
						} conns_;


				};
			}
		}
	}
}

#endif



