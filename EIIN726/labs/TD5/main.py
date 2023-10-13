import flet as ft
import flet.canvas as cv


class State:
    x: float
    y: float


def pan_start(e: ft.DragStartEvent):
    state.x = e.local_x
    state.y = e.local_y


def pan_update(e: ft.DragUpdateEvent):
    cp.shapes.append(
        cv.Line(
            state.x, state.y, e.local_x, e.local_y, paint=ft.Paint(stroke_width=3)
        )
    )
    cp.update()
    state.x = e.local_x
    state.y = e.local_y


def clear():
    pass


def parse():
    pass


# === Main ===

state = State()

cp = cv.Canvas(
    [
        cv.Fill(
            ft.Paint(color="red")
        ),
    ],
    content=ft.GestureDetector(
        on_pan_start=pan_start,
        on_pan_update=pan_update,
        drag_interval=10,
    ),
    expand=False,
)


def main(page: ft.Page):
    page.title = "Lingrandient"

    drawing_canvas_container = ft.Container(
        cp,
        border_radius=5,
        width=512,
        height=512,
    )

    right_column = ft.Column(
        controls=[
            ft.Row(
                controls=[
                    ft.OutlinedButton("Clear", on_click=clear),
                    ft.OutlinedButton("Parse", on_click=parse)
                ]
            )
        ]
    )

    view = ft.Row(
        controls=[drawing_canvas_container, right_column],
    )

    page.add(view)


ft.app(target=main)
