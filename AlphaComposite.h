#pragma once
#include <QGridLayout>
#include "AlphaWidget.h"

namespace Alpha
{
	class AlphaComposite:public AlphaWidget
	{
		Q_OBJECT

	public:

#pragma region Constructors/Destructors

		AlphaComposite(QWidget *parent=nullptr);
		~AlphaComposite();

#pragma endregion

#pragma region **** Heritage ****

	public:

	protected:

	private:

#pragma endregion

#pragma region **** Accessors ****

	public:
		SharedPtr<QGridLayout> getGridLayout()const;
		void setGridLayout( const SharedPtr<QGridLayout>& object );

	protected:

	private:

#pragma endregion

#pragma region **** Methods ****

	public:
		void loadPage(const QString& filePath);
		
	protected:

	private:

#pragma endregion

	private:

		class Private;
		Private* const d;
	};
}