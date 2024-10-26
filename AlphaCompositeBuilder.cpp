#include "stdafx.h"
#include "AlphaCompositeBuilder.h"

#include <QLabel>
#include <QPushButton>

namespace Alpha
{
#pragma region Anonymous

	namespace
	{

	}

#pragma endregion

#pragma  region Private

	class AlphaCompositeBuilder::Private
	{
	public:

	};

#pragma endregion

#pragma region Constructors/Destructors

	AlphaCompositeBuilder::AlphaCompositeBuilder( QWidget* parent )
		:d( new Private() ), AlphaWidget( parent )
	{

	}

	AlphaCompositeBuilder::~AlphaCompositeBuilder()
	{
		delete d;
	}
#pragma endregion

#pragma region **** Heritage ****

#pragma endregion

#pragma region **** Accessors ****

#pragma endregion

#pragma region **** Methods ****
	SharedPtr<QGridLayout> AlphaCompositeBuilder::buildMainLayout( const QDomDocument& document )
	{
		const auto resultGridLayout = refNew<QGridLayout>();
		resultGridLayout->setSizeConstraint(QLayout::SetMaximumSize);

		QDomNodeList colPage = document.elementsByTagName( "page" );
		if ( const auto size = colPage.size(); size > 1 )
		{
			qWarning()<<"/!\\ Xml Page tag wrongly used at l."<<colPage.at(1).lineNumber();
			return resultGridLayout;
		}

		const auto currentPage = colPage.at( 0 ).toElement();
		const auto colChildNodes = currentPage.childNodes();
		if ( const auto size = colChildNodes.size(); size > 1 )
		{
			qWarning() << "/!\\ Xml Table tag wrongly used at l." << colChildNodes.at( 1 ).lineNumber();
			return resultGridLayout;
		}

		const auto childNode = colChildNodes.at(0).toElement();
		configureTable(childNode, resultGridLayout);

		return resultGridLayout;
	}

	void AlphaCompositeBuilder::configureTable( const QDomElement& node, const SharedPtr<QGridLayout>& resultGridLayout )
	{
		const auto colChildNode = node.childNodes();
		for ( int index{ 0 }; index < colChildNode.size(); ++index )
		{
			const auto currentNode = colChildNode.at(index).toElement();
			if ( const auto tagName = currentNode.tagName(); tagName != "tr" )
			{
				qWarning() << "/!\\ Xml "<< tagName <<" tag wrongly used at l." << currentNode.lineNumber();
				return;
			}

			configureTr(currentNode, resultGridLayout, index);
		}
	}

	void AlphaCompositeBuilder::configureTr( const QDomElement& node, const SharedPtr<QGridLayout>& resultGridLayout, int rowNumber )
	{
		const auto colChildNode = node.childNodes();
		for ( int index{ 0 }; index < colChildNode.size(); ++index )
		{
			const auto currentNode = colChildNode.at( index ).toElement();
			if ( const auto tagName = currentNode.tagName(); tagName != "td" )
			{
				qWarning() << "/!\\ Xml " << tagName << " tag wrongly used at l." << currentNode.lineNumber();
				return;
			}

			configureTd( currentNode, resultGridLayout, rowNumber,index);
		}
	}

	void AlphaCompositeBuilder::configureTd( const QDomElement& node, const SharedPtr<QGridLayout>& resultGridLayout, int rowNumber, int columnNumber )
	{
		const auto colChildNode = node.childNodes();
		for ( int index{ 0 }; index < colChildNode.size(); ++index )
		{
			const auto currentNode = colChildNode.at( index ).toElement();
			
			const auto tagName = currentNode.tagName();

			if ( tagName == "table" )
			{
				const auto newTable = refNew<QGridLayout>();
				newTable->setSizeConstraint( QLayout::SetMaximumSize );
				configureTable(currentNode,newTable);
				resultGridLayout->addLayout(newTable.get(),rowNumber,columnNumber);
			}
			else
				resultGridLayout->addWidget(extractWidget(currentNode).get(),rowNumber,columnNumber);
		}
	}

	SharedPtr<QWidget> AlphaCompositeBuilder::extractWidget( const QDomElement& node )
	{
		SharedPtr<QWidget> resultWidget;
		const auto currentNode = node.toElement();
		const auto tagName = currentNode.tagName();

		if( tagName == "button" )
			resultWidget = extractButton(node);
		else if( tagName =="label" )
			resultWidget = extractLabel(node);

		return resultWidget;
	}

	SharedPtr<QWidget> AlphaCompositeBuilder::extractButton( const QDomElement& node )
	{
		const auto button = refNew<QPushButton>();

		button->setText( node.attribute("text"));

		return button;
	}

	SharedPtr<QWidget> AlphaCompositeBuilder::extractLabel( const QDomElement& node )
	{
		const auto label = refNew<QLabel>();

		label->setText( node.attribute( "text" ) );

		return label;
	}

#pragma endregion

}