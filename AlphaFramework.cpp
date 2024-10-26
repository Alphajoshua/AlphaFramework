#include "stdafx.h"
#include "AlphaFramework.h"
#include "AlphaComposite.h"

namespace Alpha
{
#pragma region Anonymous

	namespace
	{

	}

#pragma endregion

#pragma  region Private

	class AlphaFramework::Private
	{
	public:
		
		SharedPtr<Ui::AlphaFrameworkClass> ui{refNew<Ui::AlphaFrameworkClass>()};
	};

#pragma endregion

#pragma region Constructors/Destructors

	AlphaFramework::AlphaFramework(QWidget* parent)
		:d(new Private()), QMainWindow(parent)
	{
		d->ui->setupUi(this);

		const auto composite = refNew<AlphaComposite>(this);
		composite->loadPage("res/homepage.xml");
		
		setCentralWidget(composite.get());
		centralWidget()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding );
		centralWidget()->update();
	}

	AlphaFramework::~AlphaFramework()
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