#pragma once
#include "SmartPointers.h"
#include <QtWidgets/QMainWindow>
#include "ui_AlphaFramework.h"

namespace Alpha
{
	class AlphaFramework:public QMainWindow, public QEnableSharedFromThis<AlphaFramework>
	{
		Q_OBJECT

	public:

#pragma region Constructors/Destructors

		AlphaFramework(QWidget* parent = nullptr);
		~AlphaFramework();

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