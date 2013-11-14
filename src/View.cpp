
#include <assert.h>

#include <GRU/Window.h>

#include <NEB/Scene.h>
#include <NEB/View.h>
#include <NEB/Camera.h>

NEB::View::View():
	scene_( NULL )
{

}
void	NEB::View::Display()
{

	if( scene_ )
	{
		scene_->Display();
	}
}




