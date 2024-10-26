#include "stdafx.h"
#include "AlphaWidget.h"

namespace Alpha
{
#pragma region Anonymous

	namespace
	{

	}

#pragma endregion

#pragma  region Private

	class AlphaWidget::Private
	{
	public:

	};

#pragma endregion

#pragma region Constructors/Destructors

	AlphaWidget::AlphaWidget( QWidget* parent )
		:d( new Private() ), QWidget(parent)
	{

	}

	AlphaWidget::~AlphaWidget()
	{
		delete d;
	}
#pragma endregion

#pragma region **** Heritage ****

#pragma endregion

#pragma region **** Accessors ****

#pragma endregion

#pragma region **** Methods ****

#pragma endregion

}