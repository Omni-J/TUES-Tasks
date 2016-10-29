package com.paynersoft.simplegame;

import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Bundle;
import android.service.wallpaper.WallpaperService;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Point;
import android.graphics.Rect;
import android.renderscript.Float2;
import android.view.MotionEvent;

import com.google.android.gms.appindexing.Action;
import com.google.android.gms.appindexing.AppIndex;
import com.google.android.gms.common.api.GoogleApiClient;
import com.lfk.justweengine.Anim.FrameAnimation;
import com.lfk.justweengine.Anim.MoveAnimation;
import com.lfk.justweengine.Anim.VelocityAnimation;
import com.lfk.justweengine.Drawable.Sprite.BaseSub;
import com.lfk.justweengine.Engine.Engine;
import com.lfk.justweengine.Engine.GameTextPrinter;
import com.lfk.justweengine.Engine.GameTexture;
import com.lfk.justweengine.Engine.GameTimer;
import com.lfk.justweengine.Info.UIdefaultData;
import com.lfk.justweengine.Drawable.Sprite.BaseSprite;
import com.lfk.justweengine.Drawable.Sprite.BaseSub;
import com.lfk.justweengine.Drawable.Sprite.FrameType;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.util.Random;

/**
 * Created by stoeff
 */

public class Game extends Engine {
    // Please init your var in constructor.

    GameTextPrinter printer;
    Paint paint;
    Canvas canvas;
    Random random;
    Bitmap backGround2X;
    Rect bg_rect;
    Point bg_scroll;
    GameTimer timer, shoottimer, enemyTimer;
    BaseSprite ship;
    float startX, startY, offsetX, offsetY;
    GameTexture[] cards;
    final int CARD = 0;
    int enemyNum = 0;
    /**
     * ATTENTION: This was auto-generated to implement the App Indexing API.
     * See https://g.co/AppIndexing/AndroidStudio for more information.
     */
    private GoogleApiClient client;

    public Game() {
        // If open debug mode. If you open debug mode, you can print log, frame number, and parse on screen.
        super(true);
        paint = new Paint();
        canvas = null;
        printer = new GameTextPrinter();
        printer.setTextColor(Color.BLACK);
        printer.setTextSize(24);
        printer.setLineSpaceing(28);
        shoottimer = new GameTimer();
        timer = new GameTimer();
        random = new Random();
        enemyTimer = new GameTimer();
    }

    // load some UI parameters. And set screen direction, default background color, set screen's scan method.
    @Override
    public void init() {
        // init UI default par, you must use at here . Some var in UIdefaultData for more phones should be init.
        UIdefaultData.init(this);
        super.setScreenOrientation(ScreenMode.PORTRAIT);
    }

    // load sprite , background , picture and other BaseSub
    @Override
    public void load() {
        //load card
        GameTexture texture1 = new GameTexture(this);
        texture1.loadFromAsset("7clubs.png");
        card = new BaseSprite(this, 100, 124, FrameType.COMMON);
        card.setTexture(texture1);
        ship.addRectFrame(0, 100, 100, 124);
        ship.addRectFrame(167, 361, 100, 124);
        ship.addAnimation(new FrameAnimation(0, 1, 1));
        ship.setPosition(UIdefaultData.centerInHorizontalX - ship.getWidthWithScale() / 2,
                UIdefaultData.screenHeight + ship.getHeightWidthScale());
        ship.setDipScale(96, 96);
        ship.addfixedAnimation("start",
                new MoveAnimation(UIdefaultData.centerInHorizontalX - ship.getWidthWithScale() / 2,
                        UIdefaultData.screenHeight - 2 * ship.getHeightWidthScale(), new Float2(10, 10)));
        ship.setName("SHIP");
        ship.setIdentifier(SHIP);
        addToSpriteGroup(ship);

        // draw bc
        GameTexture tex = new GameTexture(this);
        if (!tex.loadFromAsset("background.jpg")) {
            fatalError("Error loading space");
        }
        backGround2X = Bitmap.createBitmap(
                UIdefaultData.screenWidth,
                UIdefaultData.screenHeight * 2,
                Bitmap.Config.ARGB_8888);
        Canvas canvas = new Canvas(backGround2X);
        Rect dst = new Rect(0, 0, UIdefaultData.screenWidth - 1,
                UIdefaultData.screenHeight);
        canvas.drawBitmap(tex.getBitmap(), null, dst, null);
        dst = new Rect(0, UIdefaultData.screenHeight,
                UIdefaultData.screenWidth,
                UIdefaultData.screenHeight * 2);
        canvas.drawBitmap(tex.getBitmap(), null, dst, null);

        bg_rect = new Rect(0, 0, UIdefaultData.screenWidth, UIdefaultData.screenHeight);
        bg_scroll = new Point(0, 0);

        cards = new GameTexture[8];
        for (int i = 0; i < 8; i++){
            cards[i] = new GameTexture(this);
            cards[i].loadFromAsset("7clubs.png");
        }

    }


    // draw and update in a new Thread
    // update message and sprite's msg
    @Override
    public void draw() {
        Canvas canvas = getCanvas();
        GameTextPrinter printer = new GameTextPrinter(canvas);
        printer.drawText("Hello", 100, 100);

        canvas = super.getCanvas();
        canvas.drawBitmap(backGround2X, bg_rect, bg_rect, paint);
        printer.setCanvas(canvas);
        printer.drawText("Engine demo", 10, 20);
    }

    @Override
    public void update() {

    }

    // receive touch event , its function depend on screen's scan mode.
    @Override
    public void touch(MotionEvent event) {
        switch (event.getAction()) {
            case MotionEvent.ACTION_MOVE:
                offsetX = event.getX() - startX;
                offsetY = event.getY() - startY;
                if (Math.abs(offsetX) > Math.abs(offsetY)) {
                    if (ship.s_position.x + offsetX > 0
                            && ship.s_position.x + offsetX +
                            ship.getHeightWidthScale() < UIdefaultData.screenWidth) {
                        ship.s_position.x += offsetX;
                        resetEvent(event);
                    }
                } else {
                    if (ship.s_position.y + offsetY > 0
                            && ship.s_position.y + offsetY +
                            ship.getHeightWidthScale() < UIdefaultData.screenHeight) {
                        ship.s_position.y += offsetY;
                        resetEvent(event);
                    }
                }
                break;
            case MotionEvent.ACTION_DOWN:
                startX = (int) event.getX();
                startY = (int) event.getY();
                break;
        }
    }

    // receive collision event , BaseSub is the father class of all the sprites and others.
    // use to solve collision event default use rect collision.
    @Override
    public void collision(BaseSub baseSub) {

    }

    private void addCard() {
        BaseSprite card;
        if (getTypeSizeFromRecycleGroup(CARD) > 0) {
            card = (BaseSprite) recycleSubFromGroup(CARD);
            card.clearAllAnimation();
            removeFromRecycleGroup(card);
        } else {
            card = new BaseSprite(this);
            card.setTexture(enemyPic);
            card.setIdentifier(CARD);
            card.setDipScale(49, 36);
        }
        double angle = 90.0;
        float speed = 5.0f;
        int lifetime = 5000;
        card.setPosition(random.nextInt(UIdefaultData.screenWidth),
                -card.getWidthWithScale());
        card.setAlive(true);
        addToSpriteGroup(card);
    }

    private void resetEvent(MotionEvent event) {
        startX = (int) event.getX();
        startY = (int) event.getY();
    }

    public static Bitmap compressImage(Bitmap image) {
        ByteArrayOutputStream baoS = new ByteArrayOutputStream();
        int options = 100;
        image.compress(Bitmap.CompressFormat.JPEG, 100, baoS);
        while (baoS.toByteArray().length / 1024 > 100) {
            baoS.reset();
            image.compress(Bitmap.CompressFormat.JPEG, options, baoS);
            options -= 10;
        }
        ByteArrayInputStream isBm = new ByteArrayInputStream(baoS.toByteArray());
        return BitmapFactory.decodeStream(isBm, null, null);
    }


    public static Bitmap compressWithMeasure(Bitmap image, int width, int height) {
        ByteArrayOutputStream baoS = new ByteArrayOutputStream();
        image.compress(Bitmap.CompressFormat.JPEG, 100, baoS);
        if (baoS.toByteArray().length / 1024 > 1024) {
            baoS.reset();
            image.compress(Bitmap.CompressFormat.JPEG, 50, baoS);
        }
        ByteArrayInputStream isBm = new ByteArrayInputStream(baoS.toByteArray());
        BitmapFactory.Options newOpts = new BitmapFactory.Options();
        newOpts.inJustDecodeBounds = true;
        Bitmap bitmap = BitmapFactory.decodeStream(isBm, null, newOpts);
        newOpts.inJustDecodeBounds = false;
        int w = newOpts.outWidth;
        int h = newOpts.outHeight;
        int be = 1;
        if (w > h && w > width) {
            be = newOpts.outWidth / width;
        } else if (w < h && h > height) {
            be = newOpts.outHeight / height;
        }
        if (be <= 0)
            be = 1;
        newOpts.inSampleSize = be;
        isBm = new ByteArrayInputStream(baoS.toByteArray());
        bitmap = BitmapFactory.decodeStream(isBm, null, newOpts);
        return compressImage(bitmap);
    }

}
