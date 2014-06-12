//#include <assert.h>

#include <Nebula/App/Base.hh>
#include <Nebula/Scene/Base.hh>
#include <Nebula/Graphics/Context/Base.hh>
#include <Nebula/Graphics/GUI/Layout/Base.hh>
#include <Nebula/Graphics/Camera/View/Free.hh>
#include <Nebula/Graphics/Camera/Projection/Perspective.hh>


neb::gfx::Context::Base::Base() {
}
neb::gfx::Context::Base::Base(sp::shared_ptr<neb::gfx::Context::Util::Parent> parent): parent_(parent) {

	printf("%s\n",__PRETTY_FUNCTION__);
}
neb::gfx::Context::Base&		neb::gfx::Context::Base::operator=(neb::gfx::Context::Base const & r){
	printf("%s\n",__PRETTY_FUNCTION__);
	return *this;
}
void		neb::gfx::Context::Base::init() {
	printf("%s\n",__PRETTY_FUNCTION__);
	
	// camera
	view_.reset(new neb::gfx::Camera::View::Free(isContextBase()));
	proj_.reset(new neb::gfx::Camera::Projection::Perspective(isContextBase()));
	//camera_->init(shared_from_this());
	
}
void		neb::gfx::Context::Base::release() {
	printf("%s\n",__PRETTY_FUNCTION__);
}
void		neb::gfx::Context::Base::resize(int w, int h) {
	viewport_.resize(w,h);
}
void		neb::gfx::Context::Base::step(neb::core::TimeStep const & ts) {

}
void		neb::gfx::Context::Base::render() {
	/**
	 * prepare rendering environment and then call the drawable
	 */

	GLUTPP_DEBUG_1_FUNCTION;
	
	auto self = sp::dynamic_pointer_cast<neb::gfx::Context::Base>(shared_from_this());
	auto app = neb::App::Base::global();

	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	
	assert(proj_);
	assert(view_);
	
	/** wrong! */	
	auto p = app->use_program(neb::program_name::e::LIGHT);
	
	//viewport_.load();
	
	proj_->load(p);
	view_->load(p);
	
	if(drawable_) {
		drawable_->draw(self);
	}
}		





