#pragma once
#include "AlphaWidget.h"
#include <QGridLayout>
#include <QDomDocument>

namespace Alpha
{
	class AlphaCompositeBuilder :public AlphaWidget
	{

	public:

#pragma region Constructors/Destructors

		AlphaCompositeBuilder( QWidget* parent = nullptr );
		~AlphaCompositeBuilder();

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
		SharedPtr<QGridLayout> buildMainLayout( const QDomDocument& document ) ;

	protected:

	private:
		void configureTable(const QDomElement& node, const SharedPtr<QGridLayout>& resultGridLayout);
		void configureTr(const QDomElement& node, const SharedPtr<QGridLayout>& resultGridLayout, int rowNumber);
		void configureTd(const QDomElement& node, const SharedPtr<QGridLayout>& resultGridLayout, int rowNumber, int columnNumber);

		SharedPtr<QWidget> extractWidget( const QDomElement& node );
		SharedPtr<QWidget> extractButton( const QDomElement& node );
		SharedPtr<QWidget> extractLabel( const QDomElement& node );

#pragma endregion

	private:

		class Private;
		Private* const d;
	};
}