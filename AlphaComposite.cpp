#include "stdafx.h"
#include "AlphaComposite.h"
#include "AlphaCompositeBuilder.h"

#include <QLabel>
#include <QPushButton>

#include <QCoreApplication>
#include <QFile>
#include <QtXml\qdom.h>

namespace Alpha
{
#pragma region Anonymous

	namespace
	{

	}

#pragma endregion

#pragma  region Private

	class AlphaComposite::Private
	{
	public:
		SharedPtr<QGridLayout> gridLayout;
	};

#pragma endregion

#pragma region Constructors/Destructors

	AlphaComposite::AlphaComposite ( QWidget* parent )
		:d ( new Private() ), AlphaWidget(parent)
	{

	}

	AlphaComposite::~AlphaComposite ()
	{
		delete d;
	}
#pragma endregion

#pragma region **** Heritage ****

#pragma endregion

#pragma region **** Accessors ****
	SharedPtr<QGridLayout> AlphaComposite::getGridLayout() const
	{
		return d->gridLayout;
	}
	void AlphaComposite::setGridLayout( const SharedPtr<QGridLayout>& object )
	{
		d->gridLayout = object;
		setLayout(object.get());
	}
#pragma endregion

#pragma region **** Methods ****
	void AlphaComposite::loadPage ( const QString& filePath )
	{
		QString fullPath = QCoreApplication::applicationDirPath()+"/"+filePath;
		QFile file( fullPath );
		if ( !file.open( QIODevice::ReadOnly ) )
		{
			qWarning()<<"Failed to open XML file:"<<filePath;
			return;
		}

		QDomDocument document;
		if ( !document.setContent( &file ) )
		{
			qWarning()<<"Failed to parse XML file:"<<filePath;
			return;
		}
		const auto compositeBuilder = refNew<AlphaCompositeBuilder>();
		SharedPtr<QGridLayout> gridLayout = compositeBuilder->buildMainLayout(document);

		setGridLayout(gridLayout);
		update();
	}
#pragma endregion

}