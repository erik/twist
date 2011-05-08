package mapeditor;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import javax.swing.JPanel;

enum Tile {

    BLOCK, SPIKES, COIN, SPAWN, GOAL, EMPTY
}

public class MapCanvas extends JPanel implements MouseMotionListener, MouseListener, KeyListener {

    private static final int tW = 64; // tile width
    private static final int tH = 64; // tile height
    private Tile[][] map;
    private Image tileset;
    private Tile currentTile;
    private int width;
    private int height;
    private String name;

    public MapCanvas(int width, int height, String name) {
        this.setSize(width * tW, height * tH);
        this.setBackground(Color.BLACK);

        this.setFocusable(true);

        this.addMouseMotionListener(this);
        this.addMouseListener(this);
        this.addKeyListener(this);

        this.width = width;
        this.height = height;
        this.name = name;
        this.map = new Tile[width][height];

        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                this.map[x][y] = Tile.EMPTY;
            }
        }

        this.currentTile = Tile.BLOCK;

        tileset = Toolkit.getDefaultToolkit().getImage(
                this.getClass().getResource("../tiles.png"));
    }

    public void setTile(int x, int y, Tile t) {
        this.map[x][y] = t;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        for (int i = 0; i < this.width; i++) {
            for (int j = 0; j < this.height; j++) {
                drawTile(g, map[j][i], i * tW, j * tH);
            }
        }

        g.setColor(new Color(0xCC, 0xCC, 0xCC));

        for (int x = 0; x <= this.width; ++x) {
            g.drawLine(x * tW, 0, x * tW, this.height * tH);
        }

        for (int y = 0; y <= this.width; ++y) {
            g.drawLine(0, y * tH, this.width * tW, y * tH);
        }

    }

    protected void drawTile(Graphics g, Tile t, int x, int y) {
        int mx = t.ordinal() % this.width;
        int my = 0;
        g.drawImage(tileset, x, y, x + tW, y + tH,
                mx * tW, my * tH, mx * tW + tW, my * tH + tH, this);
    }

    @Override
    public String toString() {
        String str = "";
        str += width;
        str += ","+height;
        str += ","+name;

        for(int x = 0; x < this.width; ++x) {
            for(int y = 0; y < this.height; ++y) {
                str += "," + this.map[x][y].ordinal();
            }
        }

        
        return str;
    }

    private void mouseStub(MouseEvent e) {
        int mx = e.getX();
        int my = e.getY();

        int x = my / tW;
        int y = mx / tH;

        if (!(x >= 0 && x < this.width)) {
            return;
        }
        if (!(y >= 0 && y < this.height)) {
            return;
        }

        if (e.isControlDown()) {
            this.setTile(x, y, Tile.EMPTY);
        } else {
            this.setTile(x, y, this.currentTile);
        }
        this.repaint();
    }

    public void mouseDragged(MouseEvent e) {
        this.mouseStub(e);
    }

    public void mouseMoved(MouseEvent e) {
    }

    public void keyPressed(KeyEvent e) {
        switch (e.getKeyCode()) {
            case KeyEvent.VK_P:
                System.out.println(toString());
                break;
            case KeyEvent.VK_UP:
                switch (this.currentTile) {
                    case EMPTY:
                        this.currentTile = Tile.BLOCK;
                        break;
                    case BLOCK:
                        this.currentTile = Tile.SPIKES;
                        break;
                    case SPIKES:
                        this.currentTile = Tile.COIN;
                        break;
                    case COIN:
                        this.currentTile = Tile.SPAWN;
                        break;
                    case SPAWN:
                        this.currentTile = Tile.GOAL;
                        break;
                    case GOAL:
                        this.currentTile = Tile.EMPTY;
                        break;
                }
                break;
        }
        System.out.println("Current tile is: " + this.currentTile.name());

    }

    public void keyTyped(KeyEvent e) {
    }

    public void keyReleased(KeyEvent e) {
    }

    public void mouseClicked(MouseEvent e) {
        this.mouseStub(e);
    }

    public void mousePressed(MouseEvent e) {
    }

    public void mouseReleased(MouseEvent e) {
    }

    public void mouseEntered(MouseEvent e) {
    }

    public void mouseExited(MouseEvent e) {
    }
}
