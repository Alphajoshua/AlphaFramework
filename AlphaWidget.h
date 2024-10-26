#pragma once
#include "SmartPointers.h"
#include <QWidget.h>

namespace Alpha
{
	class AlphaWidget:public QWidget, public SharedPtrFromThis<AlphaWidget>
	{
		Q_OBJECT;

	public:

#pragma region Constructors/Destructors

		AlphaWidget( QWidget* parent = nullptr);
		~AlphaWidget();

#pragma endregion

#pragma region **** Heritage ****

	public:

	protected:

	private:

#pragma endregion

#pragma region **** Accessors ****

	public:

	protected:

	private:

#pragma endregion

#pragma region **** Methods ****

	public:

	protected:

	private:

#pragma endregion

	private:

		class Private;
		Private* const d;
	};
}