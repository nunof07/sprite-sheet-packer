#ifndef SPRITEATLASPREVIEW_H
#define SPRITEATLASPREVIEW_H

#include <QtWidgets>
#include "SpriteAtlas.h"
#include "ImageFormat.h"

namespace Ui {
class SpriteAtlasPreview;
}

class PreviewGraphicsScene: public QGraphicsScene {
    Q_OBJECT
public:
    explicit PreviewGraphicsScene(QWidget *parent = 0);

    void setView(QGraphicsView* view) { _view = view; }
    virtual void drawBackground(QPainter *painter, const QRectF &rect);

private:
    QGraphicsView* _view;
    QBrush         _backgroundBrush;
};

class SpriteAtlasPreview : public QWidget
{
    Q_OBJECT

public:
    explicit SpriteAtlasPreview(QWidget *parent = 0);
    ~SpriteAtlasPreview();

    void setAtlas(const SpriteAtlas& atlas, PixelFormat pixelFormat, bool premultiplied);

public slots:
    void on_toolButtonZoomOut_clicked();
    void on_toolButtonZoomIn_clicked();
    void on_toolButtonZoom1x1_clicked();
    void on_toolButtonZoomFit_clicked();
    void on_zoomSlider_valueChanged(int value);
    void on_displayOutlinesCheckBox_clicked(bool checked);

private:
    Ui::SpriteAtlasPreview* ui;

    PreviewGraphicsScene*   _scene;
    QGraphicsItemGroup*     _outlinesGroup;
};

#endif // SPRITEATLASPREVIEW_H